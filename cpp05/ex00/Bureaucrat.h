#ifndef BUREAUCRAT
#define BUREAUCRAT

#include <iostream>

class Bureaucrat
{
      private:
	const std::string name;
	int grade;
      public:
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

	int getGrade() const;
	const std::string& getName() const;

	void incrementGrade();	
	void decrementGrade();

	class GradeTooHighException : public std::exception
	{
		public:
		virtual	const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual	const char *what() const throw();
	};
      
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ber);

#endif
