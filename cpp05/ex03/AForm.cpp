#include "AForm.hpp"

AForm::AForm(void) : name("Default"), gradeToSign(20), gradeToExecute(10), sign(false)
{
	std::cout << "Default Contructor Calling" << std::endl;
};

AForm::AForm(std::string form, int sign, int execute) : name(form), gradeToSign(sign), gradeToExecute(execute), sign(false)
{
	std::cout << "Params Contructor Calling" << std::endl;
	if (sign > MIN_GRADE || execute > MIN_GRADE)
		throw AForm::GradeTooLowException();
	else if (sign < MAX_GRADE || execute < MAX_GRADE)
		throw AForm::GradeTooHighException();
};

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		this->sign = src.getSign();
	}
	return (*this);
};

AForm::AForm(const AForm &copy): name(copy.getName()), gradeToSign(copy.getGradeToSign()), gradeToExecute(copy.getGradeToExecute())
{
	if (copy.getGradeToSign() > MIN_GRADE || copy.getGradeToExecute()  > MIN_GRADE)
		throw AForm::GradeTooLowException();
	else if (copy.getGradeToSign() < MAX_GRADE || copy.getGradeToExecute() < MAX_GRADE)
		throw AForm::GradeTooHighException();
	*this = copy;
};

int AForm::getGradeToSign(void) const
{
	return(this->gradeToSign);
};

int AForm::getGradeToExecute(void) const
{
	return(this->gradeToExecute);
};

std::string AForm::getName(void) const
{
	return(this->name);
};

bool AForm::getSign(void) const
{
	return(this->sign);
};

void AForm::beSigned(Bureaucrat &politic)
{
	if (politic.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	this->sign = true;
};


void AForm::setSign(bool sign)
{
	this->sign = sign;
};

AForm::~AForm(void)
{
	std::cout << "Destructor Form Calling" << std::endl;
};

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->sign)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooLowException();
};

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form: " << form.getName() << std::endl << "grade to sign: " << form.getGradeToSign() << std::endl << "grade to execute: " << form.getGradeToExecute() << std::endl << "is signed: " << form.getSign() << ".";
	return os;
};

char const * AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
};

char const *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
};

char const *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
};