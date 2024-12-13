#pragma once

#include <iostream>
#include <fstream>
#include <exception>
#include "Bureaucrat.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		const int			gradeToSign;
		const int			gradeToExecute;
		bool				sign;
	public:
		AForm(void);
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &copy);
		virtual ~AForm(void) = 0;

		AForm&operator=(const AForm &src);

		std::string		getName(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;
		bool			getSign(void) const;
		void			beSigned(Bureaucrat &politic);
		void			setSign(bool sign);
		void			execute(Bureaucrat const &executor) const;
		virtual void	action(void) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);