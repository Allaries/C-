#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat bob("Thierry", 149);
        Form work("some paper", 148, 120);
        std::cout << bob << std::endl;
        std::cout << work << std::endl;
        bob.signForm(work);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}