#ifndef AFORM
#define AFORM

#include <iostream>
#include <exception> 

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		const int gradeSign;
		bool isSigned;
		const int gradeExcute;
	public:
		AForm(const std::string& name, int gradeSign, int gradeExcute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		void execute(const Bureaucrat &executor) const;
		virtual void action()  const = 0;

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
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
