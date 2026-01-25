#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(const std::string &name, int Grade) : name(name)
{
	if (Grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (Grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = Grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
        *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
        if (this != &other)
        {
		grade = other.grade;
        }
        return (*this);
}
int Bureaucrat::getGrade() const
{
	return grade;
}
const std::string& Bureaucrat::getName() const
{
	return name;
}
void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooHighException();
	grade++;
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

Bureaucrat::~Bureaucrat()
{
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& ber)
{
	os << ber.getName() << ", Bureaucrat Grade " << ber.getGrade();
	return os;
}
