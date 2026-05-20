#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		int	i;
		int j;
		i = 1;
		while (argv[i])
		{
			j = -1;
			while (argv[i][++j])
				argv[i][j] = toupper(argv[i][j]);
			cout << argv[i];
			i++;
			if (argv[i] != NULL)
				cout << " ";
		}
	}
	cout << "\n";
	return (0);
}