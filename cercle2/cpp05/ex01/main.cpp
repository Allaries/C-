#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat bob("Thierry", 149);
        std::cout << bob.getGrade() << std::endl;
        bob.DecrementGrade();
        std::cout << bob.getGrade() << std::endl;
        bob.DecrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}