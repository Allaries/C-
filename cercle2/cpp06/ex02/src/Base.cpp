#include "../include/Base.hpp"

Base *generate(void)
{
	switch (std::rand() % 3)
    {
        case 0:
			return new A();
        case 1:
			return new B();
        default:
			return new C();
    }
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "This sould'nt be seen by a random user O.O" << std::endl;
}

void identify(Base &p)
{
    try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; return; }
    catch (std::exception& e) {}

    try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; return; }
    catch (std::exception& e) {}

    try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; return; }
    catch (std::exception& e) {}

    std::cout << "Unknown" << std::endl;
}


Base::~Base()
{}