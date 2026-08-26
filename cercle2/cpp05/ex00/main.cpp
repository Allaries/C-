#include "include/Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat bob("Thierry", 149);
        
        std::cout << bob << std::endl;
        bob.DecrementGrade();
        std::cout << bob << std::endl;
        bob.DecrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat Thierry("BoB", 2);
        
        std::cout << Thierry << std::endl;
        Thierry.IncrementGrade();
        std::cout << Thierry << std::endl;
        Thierry.IncrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}