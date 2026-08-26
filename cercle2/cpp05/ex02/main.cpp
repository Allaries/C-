#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "include/PresidentialPardonForm.hpp"

int main(void)
{
    try
    {
        AForm* work = new PardonForm();
        Bureaucrat bob("Thierry", 149);
        std::cout << bob << std::endl;
        std::cout << *work << std::endl;
        work->execute(bob);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}