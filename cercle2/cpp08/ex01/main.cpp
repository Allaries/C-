#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    Span sp = Span(10000);

    for (int i = 0; i < 10000; i++)
    {
        int n = std::rand();
        sp.addNumber(n);
    }

    try
    {
        std::cout << "Shortest span: "
                  << sp.shortestSpan() << std::endl;

        std::cout << "Longest span: "
                  << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
// int	main(void)
// {
// 	Span A(5);
// 	try
// 	{
// 		A.addNumber(11);
// 		A.addNumber(39);
// 		A.addNumber(24);
// 		A.addNumber(97);
// 		A.addNumber(56);
// 		std::cout << A.shortestSpan() << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
	
// }