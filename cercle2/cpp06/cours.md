# C++ Module 06 — C++ casts · Fiche de travail complète

> **Comment utiliser cette fiche.** Elle contient tout ce qu'il faut savoir : théorie des casts,
> algorithmes détaillés, pièges de C++98, squelettes de fichiers, Makefile, tests et questions
> de défense. Les *structures* sont données, la *logique* est décrite en pseudo-code : c'est
> volontaire — en soutenance on te demandera d'expliquer chaque ligne, et le sujet prévoit une
> modification en direct. Écris le code toi-même à partir des algorithmes, tu le tiendras.

---

## Sommaire

1. [Règles du module à ne jamais oublier](#1-règles-du-module-à-ne-jamais-oublier)
2. [Théorie : les 4 casts C++](#2-théorie--les-4-casts-c)
3. [Makefile type](#3-makefile-type)
4. [ex00 — ScalarConverter](#4-ex00--scalarconverter)
5. [ex01 — Serializer](#5-ex01--serializer)
6. [ex02 — Identify real type](#6-ex02--identify-real-type)
7. [Pièges C++98 (liste noire)](#7-pièges-c98-liste-noire)
8. [Checklist finale + questions de défense](#8-checklist-finale--questions-de-défense)

---

## 1. Règles du module à ne jamais oublier

| Règle | Détail |
|---|---|
| Compilation | `c++ -Wall -Wextra -Werror` et doit passer avec `-std=c++98` |
| Arborescence | `ex00/`, `ex01/`, `ex02/` — chacun avec son `Makefile` |
| Nommage | classes en `UpperCamelCase`, fichier = nom de la classe (`ScalarConverter.hpp/.cpp`) |
| Interdits | `using namespace`, `friend` → **-42** · STL (containers/`<algorithm>`) → **-42** · `*printf`, `*alloc`, `free` → **0** |
| Include guards | obligatoires, sinon **0** |
| Implémentation dans un `.hpp` | interdit (sauf templates) → **0** |
| Forme canonique orthodoxe | obligatoire **sauf mention contraire** (ex02 en est explicitement dispensé) |
| Fuites mémoire | tout `new` doit avoir son `delete` |
| Sortie | chaque message se termine par `\n`, sur la sortie standard |

**Règle additionnelle du module (chapitre III)** : chaque exercice doit utiliser **un type de cast
précis**, et ton choix sera discuté en défense. Le module est construit exactement pour ça :

- ex00 → `static_cast`
- ex01 → `reinterpret_cast`
- ex02 → `dynamic_cast`

(`const_cast` n'est utilisé nulle part ici, mais il faut savoir l'expliquer.)

---

## 2. Théorie : les 4 casts C++

En C on écrivait `(int)x`. C'est un cast « fourre-tout » : le compilateur essaie successivement
plusieurs conversions et te laisse faire n'importe quoi sans prévenir. C++ le découpe en 4 opérateurs
explicites, **cherchables au grep**, chacun avec un pouvoir limité et vérifié à la compilation.

### 2.1 `static_cast<T>(expr)`

Conversion **vérifiée à la compilation**, entre types qui ont une relation logique connue.

```cpp
double d = 4.2;
int    i = static_cast<int>(d);     // 4  (troncature, pas d'arrondi)
char   c = static_cast<char>(65);   // 'A'
Base*  b = static_cast<Derived*>(p) // upcast : toujours sûr
```

- Conversions numériques (int ↔ float ↔ double ↔ char).
- Upcast (Derived* → Base*) : sûr.
- Downcast (Base* → Derived*) : **compile mais non vérifié à l'exécution** → dangereux, c'est le
  rôle de `dynamic_cast`.
- Ne peut pas enlever un `const`.

> **Point de défense** : `static_cast<int>(4.9)` donne `4`. La troncature va vers zéro,
> `static_cast<int>(-4.9)` donne `-4`.

### 2.2 `reinterpret_cast<T>(expr)`

Réinterprétation brute du motif binaire. Le compilateur ne vérifie **rien** : « prends ces octets et
considère-les comme un `T` ». Usage typique : pointeur ↔ entier, pointeur ↔ pointeur non lié.

```cpp
uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
Data*     p   = reinterpret_cast<Data*>(raw);
```

C'est le cast le plus dangereux : il n'est portable que si tu refais l'opération inverse exactement
(aller-retour). C'est le sujet complet de l'ex01.

### 2.3 `const_cast<T>(expr)`

Le **seul** cast capable d'ajouter ou retirer `const` / `volatile`. Ne change aucun autre aspect du
type.

```cpp
const int  a = 42;
int*       p = const_cast<int*>(&a);  // *p = 0; → comportement indéfini si l'objet est réellement const
```

Usage légitime : appeler une vieille API C qui prend `char*` alors que ta donnée est `const char*`
et que tu sais qu'elle ne sera pas modifiée. Écrire dans un objet réellement `const` est un
**undefined behavior**.

### 2.4 `dynamic_cast<T>(expr)`

Downcast **vérifié à l'exécution**, uniquement sur des types **polymorphes** (au moins une fonction
virtuelle — en pratique un destructeur virtuel). Il utilise le RTTI (Run-Time Type Information)
stocké via la vtable.

```cpp
A* a = dynamic_cast<A*>(basePtr);   // renvoie NULL si ce n'est pas un A
A& r = dynamic_cast<A&>(baseRef);   // lance une exception si ce n'est pas un A
```

Deux comportements à connaître par cœur :

| Forme | Échec |
|---|---|
| pointeur | renvoie `NULL` (`0` en C++98) |
| référence | **lance** `std::bad_cast` |

La raison : une référence ne peut pas être « nulle », il n'y a donc pas de valeur d'échec possible →
l'exception est le seul mécanisme disponible. C'est exactement ce que l'ex02 fait tester.

### 2.5 Tableau récapitulatif

| Cast | Vérifié quand | Sert à | Coût runtime |
|---|---|---|---|
| `static_cast` | compilation | conversions logiques, upcast | nul |
| `reinterpret_cast` | jamais | réinterprétation binaire | nul |
| `const_cast` | compilation | ajouter/retirer `const` | nul |
| `dynamic_cast` | **exécution** | downcast sûr sur type polymorphe | oui (RTTI) |

---

## 3. Makefile type

À copier dans chaque `exNN/` en changeant `NAME` et `SRCS`.

```make
NAME    = convert

CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS    = main.cpp ScalarConverter.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
        $(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
        $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
        rm -f $(OBJS)

fclean: clean
        rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

> Attention : les recettes commencent par une **tabulation**, pas des espaces.
> Règles obligatoires : `all`, `clean`, `fclean`, `re`, `$(NAME)`. Pas de relink inutile.

---

## 4. ex00 — ScalarConverter

**Cast à utiliser : `static_cast`.**

### 4.1 Ce qui est demandé

Une classe `ScalarConverter`, **non instanciable**, avec une seule méthode statique
`convert(const std::string&)`. Elle :

1. détecte le type du littéral passé en argument (char, int, float ou double) ;
2. le convertit depuis la chaîne vers son type réel ;
3. le convertit **explicitement** vers les 3 autres types ;
4. affiche les 4 résultats.

### 4.2 Rendre une classe non instanciable

L'astuce canonique : déclarer toute la forme canonique en **privé**. Personne ne peut appeler le
constructeur depuis l'extérieur, et comme la classe n'a que des membres statiques, elle reste
utilisable via `ScalarConverter::convert(...)`.

```cpp
// ScalarConverter.hpp
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
    ScalarConverter();                                        // jamais défini/appelé
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

public:
    static void convert(const std::string& literal);
};

#endif
```

> En défense on te demandera : *pourquoi privé et pas juste « je ne l'instancie pas » ?*
> Réponse : le sujet dit « **must not be instantiable by users** » → c'est le compilateur qui doit
> l'interdire, pas la bonne volonté de l'utilisateur.

### 4.3 Détection du type du littéral

Ordre de test recommandé (du plus spécifique au plus général) :

```
1. Pseudo-littéraux float  : "-inff", "+inff", "nanf"
2. Pseudo-littéraux double : "-inf",  "+inf",  "nan"
3. CHAR   : longueur == 1 ET le caractère n'est pas un chiffre
            (optionnel : accepter aussi la forme "'c'" de longueur 3)
4. INT    : [+|-] suivi uniquement de chiffres, au moins un chiffre
5. FLOAT  : [+|-] chiffres '.' chiffres 'f'   → un seul '.', se termine par 'f',
            au moins un chiffre, rien d'autre
6. DOUBLE : [+|-] chiffres '.' chiffres       → un seul '.', pas de 'f'
7. sinon  : littéral invalide → message d'erreur clair
```

Points d'attention :

- `"42"` est un **int**, `"42.0"` un **double**, `"42.0f"` un **float**, `"4"` un **int** (pas un char,
  car c'est un chiffre), `"c"` un **char**.
- `"."`, `"f"`, `"-"`, `".f"`, `"1.2.3"`, `"1.2ff"` sont invalides.
- Décide si tu acceptes `"4.f"` / `".5f"` et sois cohérent : le sujet ne l'impose pas, mais ton
  correcteur testera des choses tordues. Documente ton choix.

### 4.4 Conversion chaîne → type réel

Le sujet autorise « toute fonction pour convertir d'une chaîne vers int, float ou double ».
En C++98 : `std::strtod`, `std::strtol`, `std::atoi` (`<cstdlib>`).

Approche simple et robuste : **tout stocker dans un `double`** une fois le type détecté.

```
si type == CHAR   → double value = static_cast<double>(literal[0]);
sinon             → double value = std::strtod(literal.c_str(), NULL);
```

Puis toutes les sorties dérivent de `value` avec des `static_cast`. Garde aussi le type détecté :
il sert à savoir s'il faut afficher `nanf` ou `nan`, et à gérer les cas spéciaux.

### 4.5 Détecter `nan` et `inf` en C++98

⚠️ `std::isnan` et `std::isinf` sont **C99 / C++11** : ils ne compilent pas proprement en
`-std=c++98 -Werror`. Utilise :

```cpp
#include <limits>

bool isNan(double v) { return v != v; }                                    // seul NaN != lui-même
bool isInf(double v) { return v ==  std::numeric_limits<double>::infinity()
                           || v == -std::numeric_limits<double>::infinity(); }
```

### 4.6 Règles d'affichage, ligne par ligne

#### `char:`

```
si valeur est nan ou inf                     → "char: impossible"
sinon si valeur < 0 ou valeur > 127          → "char: impossible"   (hors de la table ASCII)
sinon si !std::isprint(static_cast<int>(v))  → "char: Non displayable"
sinon                                        → "char: '" << static_cast<char>(v) << "'"
```

`std::isprint` vient de `<cctype>`. Passe-lui un `int` valide (0–255) pour éviter tout UB.

> Note : le sujet montre `./convert 0 → char: Non displayable` (0 = `NUL`, non imprimable) et
> `./convert 42.0f → char: '*'` (42 = code ASCII de `*`). Le test porte bien sur la **valeur
> numérique**, pas sur les chiffres de la chaîne.

#### `int:`

```
si nan ou inf                                              → "int: impossible"
si v < std::numeric_limits<int>::min()
   ou v > std::numeric_limits<int>::max()                  → "int: impossible"
sinon                                                      → static_cast<int>(v)
```

`<limits>` est le header « numeric limits » évoqué par le sujet.

#### `float:`

```
si nan                → "float: nanf"
si +inf               → "float: +inff"      (ou "inff" — reste cohérent)
si -inf               → "float: -inff"
sinon                 → static_cast<float>(v) suivi de 'f'
```

Détail de formatage : `42` doit s'afficher `42.0f`, pas `42f`. Deux techniques :

```cpp
// A) précision fixe à 1 décimale
std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;   // <iomanip>

// B) ajouter ".0" seulement si la valeur est entière
if (f == static_cast<int>(f) && !isInf(f))
    std::cout << f << ".0f" << std::endl;
else
    std::cout << f << "f" << std::endl;
```

La méthode (A) est plus simple mais tronque `4.25f` en `4.2f`. La méthode (B) préserve les
décimales. Choisis-en une, sache justifier pourquoi.

#### `double:`

Même logique, sans le `f` final : `nan`, `+inf`, `-inf`, sinon la valeur avec `.0` si entière.

### 4.7 Squelette de `main.cpp`

```cpp
#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
```

### 4.8 Batterie de tests à faire tourner

```sh
./convert 0          # char: Non displayable / int: 0 / float: 0.0f / double: 0.0
./convert 42.0f      # char: '*' / int: 42 / float: 42.0f / double: 42.0
./convert nan        # char: impossible / int: impossible / float: nanf / double: nan
./convert nanf
./convert +inf
./convert -inff
./convert 'a'        # ou : ./convert a
./convert -42
./convert 2147483648   # int: impossible (dépassement)
./convert -2147483649
./convert 1e40         # à toi de décider : littéral invalide ou double ?
./convert 4.2
./convert 4.2f
./convert 127
./convert 128        # char: impossible
./convert -1         # char: impossible
./convert 65         # char: 'A'
./convert ""         # entrée vide
./convert hello      # invalide
./convert 1.2.3      # invalide
```

Vérifie aussi : `valgrind ./convert 42` → 0 leak (il n'y a aucun `new` ici, donc c'est facile).

---

## 5. ex01 — Serializer

**Cast à utiliser : `reinterpret_cast`.**

### 5.1 Idée

Un pointeur, c'est une adresse, donc un nombre. `uintptr_t` est un type entier non signé
**garanti assez large pour contenir un pointeur** sans perte. L'exercice consiste à faire
l'aller-retour `Data* → uintptr_t → Data*` et à vérifier qu'on retombe sur le même pointeur.

### 5.2 `uintptr_t` en C++98

`<cstdint>` est C++11. En C++98 tu inclus l'en-tête C :

```cpp
#include <stdint.h>   // uintptr_t
```

Cela compile avec `-std=c++98 -Wall -Wextra -Werror` sur les machines 42. Si jamais ton
compilateur râle, ajoute `#include <cstddef>` ou vérifie que tu n'as pas oublié l'include.

### 5.3 Les fichiers

```cpp
// Data.hpp
#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
    int         id;
    std::string name;
    // structure "non vide" comme exigé par le sujet
};

#endif
```

```cpp
// Serializer.hpp
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data*     deserialize(uintptr_t raw);
};

#endif
```

L'implémentation dans le `.cpp` fait une ligne chacune : `reinterpret_cast<uintptr_t>(ptr)` et
`reinterpret_cast<Data*>(raw)`.

> ⚠️ Le `.cpp` doit contenir les définitions, y compris celles de la forme canonique privée si tu
> les définis. Les laisser **déclarées mais non définies** est aussi valable (personne ne peut les
> appeler), et c'est même plus explicite. Sois prêt à justifier.

### 5.4 Squelette de test

```cpp
#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data      d;
    d.id   = 42;
    d.name = "quarante-deux";

    uintptr_t raw = Serializer::serialize(&d);
    Data*     ptr = Serializer::deserialize(raw);

    std::cout << "original : " << &d  << std::endl;
    std::cout << "raw      : " << raw << std::endl;
    std::cout << "restored : " << ptr << std::endl;
    std::cout << "equal    : " << (ptr == &d ? "yes" : "no") << std::endl;

    // prouve que les données sont intactes à travers l'aller-retour
    std::cout << ptr->id << " " << ptr->name << std::endl;
    return 0;
}
```

### 5.5 Ce qu'on te demandera en défense

- *Pourquoi `reinterpret_cast` et pas `static_cast` ?* → `static_cast` refuse la conversion
  pointeur ↔ entier : il n'existe pas de relation logique entre les deux, seulement une
  identité de représentation binaire.
- *Pourquoi `uintptr_t` et pas `int` / `unsigned int` ?* → `int` peut être trop petit (4 octets vs
  un pointeur 8 octets en 64 bits) → troncature et pointeur invalide. `uintptr_t` est
  dimensionné pour ça par la norme.
- *Pourquoi non signé ?* → une adresse n'a pas de signe ; le signe compliquerait comparaisons et
  décalages.
- *Est-ce sûr ?* → uniquement en aller-retour, sur un pointeur valide. Fabriquer un `uintptr_t`
  à la main et le déréférencer = comportement indéfini.

---

## 6. ex02 — Identify real type

**Cast à utiliser : `dynamic_cast`.**

### 6.1 Les classes

```cpp
// Base.hpp
#ifndef BASE_HPP
#define BASE_HPP

class Base
{
public:
    virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
```

Tu peux tout mettre dans `Base.hpp` (`A`, `B`, `C` sont vides) ou faire un fichier par classe.
Le destructeur virtuel doit être **défini** dans le `.cpp` (`Base::~Base() {}`).

> Le sujet dispense explicitement ces 4 classes de la forme canonique orthodoxe.
> Le destructeur **virtuel** n'est pas décoratif : sans lui, la classe n'est pas polymorphe et
> `dynamic_cast` **ne compile pas**. Et il évite les fuites lors du `delete` via `Base*`.

### 6.2 `generate()`

```cpp
Base* generate(void)
{
    switch (std::rand() % 3)          // <cstdlib>
    {
        case 0:  return new A();
        case 1:  return new B();
        default: return new C();
    }
}
```

Appelle `std::srand(std::time(NULL));` **une seule fois** au début du `main` (`<ctime>`), sinon
`rand()` renvoie toujours la même séquence.

### 6.3 `identify(Base* p)` — version pointeur

```
si dynamic_cast<A*>(p) != NULL  → afficher "A"
sinon si dynamic_cast<B*>(p)    → afficher "B"
sinon si dynamic_cast<C*>(p)    → afficher "C"
sinon                           → afficher "Unknown"
```

Pense à gérer `p == NULL` (le `dynamic_cast` renverra `NULL` de toute façon, mais un test explicite
est plus lisible).

### 6.4 `identify(Base& p)` — version référence

Contrainte du sujet : **utiliser un pointeur à l'intérieur de cette fonction est interdit.**
Donc pas de `&p`, pas de `dynamic_cast<A*>(&p)`. Le seul moyen est le `dynamic_cast` sur référence,
qui **lance une exception** en cas d'échec :

```cpp
void identify(Base& p)
{
    try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; return; }
    catch (std::exception& e) {}

    try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; return; }
    catch (std::exception& e) {}

    try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; return; }
    catch (std::exception& e) {}

    std::cout << "Unknown" << std::endl;
}
```

⚠️ **Piège majeur** : l'exception lancée est `std::bad_cast`, qui est déclarée dans `<typeinfo>` —
header **interdit** par le sujet. Solution : attrape la classe de base `std::exception`, déclarée
dans `<exception>`, qui est autorisée. Ne mentionne jamais `std::bad_cast` par son nom dans ton code.

Le `(void)` devant le cast évite un warning « expression result unused » avec `-Wextra -Werror`.
Tu peux aussi écrire `A& ref = dynamic_cast<A&>(p); (void)ref;`.

### 6.5 `main` de test

```cpp
int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    for (int i = 0; i < 9; ++i)
    {
        Base* p = generate();
        std::cout << "ptr -> "; identify(p);
        std::cout << "ref -> "; identify(*p);
        delete p;                       // pas de fuite (destructeur virtuel !)
        std::cout << "---" << std::endl;
    }
    return 0;
}
```

Les deux lignes de chaque tour doivent afficher la **même** lettre. Vérifie avec
`valgrind --leak-check=full ./identify`.

### 6.6 Questions de défense

- *Pourquoi `dynamic_cast` et pas `static_cast` ?* → `static_cast<A*>(basePtr)` compile mais ne
  vérifie rien : si l'objet est un `B`, tu obtiens un pointeur invalide utilisé silencieusement.
  `dynamic_cast` interroge le RTTI à l'exécution et te renvoie `NULL`.
- *Pourquoi le destructeur doit-il être virtuel ?* → deux raisons : rendre la classe polymorphe
  (condition sine qua non de `dynamic_cast`) et garantir l'appel du bon destructeur via `Base*`.
- *Pourquoi la version référence lance-t-elle au lieu de renvoyer une valeur d'échec ?* → il
  n'existe pas de « référence nulle » ; l'exception est le seul canal d'erreur possible.
- *Coût ?* → `dynamic_cast` a un coût à l'exécution (parcours de la hiérarchie RTTI), contrairement
  aux 3 autres casts qui sont gratuits.

---

## 7. Pièges C++98 (liste noire)

| Ce qui casse la compilation en `-std=c++98 -Werror` | Remplacement |
|---|---|
| `std::isnan`, `std::isinf` | `v != v` · comparaison à `numeric_limits<double>::infinity()` |
| `<cstdint>` | `<stdint.h>` |
| `std::to_string`, `std::stoi`, `std::stof` | `std::strtod`, `std::strtol`, `std::ostringstream` |
| `nullptr` | `NULL` ou `0` |
| `auto`, `for (x : y)`, lambdas, `= delete`, `override` | rien de tout ça |
| `long long` | `long` |
| variable déclarée non utilisée | `(void)var;` |
| `using namespace std;` | préfixe `std::` partout (interdit, **-42**) |

Headers utiles pour ce module : `<iostream>`, `<string>`, `<iomanip>`, `<limits>`, `<cstdlib>`,
`<cctype>`, `<cmath>`, `<ctime>`, `<exception>`, `<stdint.h>`.

---

## 8. Checklist finale + questions de défense

### Avant de push

- [ ] `make re` sans aucun warning dans chaque `exNN/`
- [ ] Recompilation forcée avec `-std=c++98` : OK
- [ ] Aucun `using namespace`, aucun `friend`, aucun `printf`/`malloc`/`free`
- [ ] Aucun container STL, aucun `<algorithm>`
- [ ] Include guards dans **tous** les `.hpp`
- [ ] Chaque `.hpp` compile seul (teste : `c++ -std=c++98 -c Truc.hpp`)
- [ ] Aucune implémentation dans un `.hpp`
- [ ] `ScalarConverter` et `Serializer` non instanciables
- [ ] `valgrind` propre sur les 3 exécutables
- [ ] ex02 : pas d'`#include <typeinfo>`, pas de pointeur dans `identify(Base&)`
- [ ] Chaque sortie se termine par un `\n`
- [ ] Fichiers rendus : `Makefile`, `*.cpp`, `*.hpp` dans `ex00/`, `ex01/`, `ex02/`
- [ ] Tu sais justifier **chaque** cast choisi

### Les 10 questions qui tombent le plus

1. Quelle est la différence entre les 4 casts C++ et le cast C `(type)x` ?
2. Pourquoi préférer les casts C++ ? *(explicites, greppables, pouvoir limité, vérifiés)*
3. Lequel est vérifié à l'exécution, et pourquoi c'est le seul ?
4. Que renvoie `dynamic_cast` sur pointeur en cas d'échec ? Et sur référence ?
5. Que se passe-t-il si tu enlèves le `virtual` du destructeur de `Base` ?
6. Comment rends-tu une classe non instanciable ? Pourquoi le sujet l'exige ?
7. Pourquoi `uintptr_t` plutôt qu'un `int` dans l'ex01 ?
8. Comment détectes-tu un dépassement de capacité vers `int` dans l'ex00 ?
9. Comment détectes-tu un NaN sans `std::isnan` ?
10. Comment distingues-tu `"42"`, `"42.0"`, `"42.0f"` et `"4"` ?

### Modification en direct : entraîne-toi

Le chapitre VIII prévoit qu'on te demande une petite modif pendant la défense. Répète ces
scénarios chez toi, chronomètre :

- ajouter le type `long` ou `bool` à la sortie de `ScalarConverter`
- accepter la notation `0x2A` (hexadécimal) en entrée
- ajouter une classe `D` dans l'ex02 et l'intégrer à `generate()` et aux deux `identify()`
- ajouter un champ à `Data` et prouver qu'il survit à la sérialisation
- changer le format d'affichage (par exemple `char = '*'` au lieu de `char: '*'`)

---

**Ordre de travail conseillé** : lis toute la section 2 (théorie) → fais l'ex01 (le plus court, il
te met dans le bain) → l'ex02 → l'ex00 en dernier (c'est le plus long, à cause du parsing et des
cas limites).