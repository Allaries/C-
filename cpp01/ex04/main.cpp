#include <iostream>
#include <fstream>

std::string	change(std::string lign, std::string rm, std::string rp)
{

	size_t pos = 0;
	size_t found;
	std::string result;
	if (rm.empty())
    	return(lign);
	while ((found = lign.find(rm, pos)) != std::string::npos)
	{
		result += lign.substr(pos, found - pos);
		result += rp;
		pos = found + rm.length();
	}
	result += lign.substr(pos);
	lign = result;
	return (result);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "try 3 argument : 1 = file name - replacing occurrence of 2 with 3\n";
		return (0);
	}
	std::string filename = argv[1];
	std::ifstream influx(filename.c_str());
	filename.append(".replace");
	std::ofstream outflux(filename.c_str());
	if (influx && outflux)
	{
		std::string lign;
		while(std::getline(influx, lign))
		{
			lign = change(lign, argv[2], argv[3]);
			outflux << lign << std::endl;
		}
	}
	else
		std::cout << "Erreur a l'ouverture du fichier" << std::endl;
}