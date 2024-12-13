#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat Ferd("Ferd", 5);
	Intern	b;
	AForm	*test;
	AForm	*shru;
	AForm	*robo;
	AForm	*presi;

	shru = b.makeForm("Presidential pardon", "lulinha");
	robo = b.makeForm("Robotomy request", "pablito");

	presi = b.makeForm("Shrubbery creation", "gigachad");
	test = b.makeForm("test", "test");

	Ferd.signForm(*shru);
	Ferd.signForm(*robo);
	Ferd.signForm(*presi);

	Ferd.executeForm(*shru);
	Ferd.executeForm(*robo);
	Ferd.executeForm(*presi);

	if (test != nullptr)
		Ferd.executeForm(*test);
	else
		std::cout << "Form not found" << std::endl;
	return (0);
}
