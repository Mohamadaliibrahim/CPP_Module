#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        // Create a Form that requires grade 50 to sign, 10 to execute
        Form f1("TopSecretDoc", 50, 10);

        // Create Bureaucrats
        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 100);

        std::cout << f1 << std::endl;
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl << std::endl;

        // b1 tries to sign f1
        b1.signForm(f1); // Should succeed
        std::cout << f1 << std::endl << std::endl;

        // b2 tries to sign f1
        b2.signForm(f1); // Should fail, already signed or no exception if it's already signed, depending on your logic
        std::cout << f1 << std::endl << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
