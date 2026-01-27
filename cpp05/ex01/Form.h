#ifndef FORM
#define FORM

#include <iostream>
#include <exception> 

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		const int gradeSign;
		bool isSigned;
		const int gradeExcute;
	public:
		Form(const std::string& name, int gradeSign, int gradeExcute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		const std::string& getName() const;
		bool isSigne() const;
		int gradeToSign() const;
		int gradeToExcute() const;

		void beSigned(const Bureaucrat& b);
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
