#include "Form.h"
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

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

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

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << "Bureaucrat : " << name << " signed this : " << f.getName() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "Bureaucrat : " << name << " Couldn't signe : " << f.getName() << " Because of " << e.what() << '\n';
	}
	
}

Bureaucrat::~Bureaucrat() {}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ber)
{
	os << ber.getName() << ", Bureaucrat Grade " << ber.getGrade();
	return os;
}
