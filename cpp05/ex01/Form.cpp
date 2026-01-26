#include "Form.h"

Form::Form(const std::string& name, int gradeSign, int gradeExcute) : 
	name(name), 
	gradeSign(gradeSign), 
	isSigne(false),
	gradeExcute(gradeExcute)
{
	if (gradeSign < 1 || gradeExcute < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExcute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : 
	name(other.name), 
	gradeSign(other.gradeSign), 
	isSigned(other.isSigned), 
	gradeExcute(other.gradeExcute){}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
		isSigned = other.isSigned;
    }
    return (*this);
}

const std::string& Form::getName() const
{
	return name;
}

bool Form::isSigne() const 
{
	return isSigne;
}

int Form::gradeSign() const
{
	return gradeSign;
}

int Form::gradeExcute() const
{
	return gradeExcute;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Grade Too Low";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName()
		<< ", Signed: " << form.isSigne()
		<< ", grade to signe: " << form.gradeSign()
		<< ", grade to Execute: " << form.gradeExcute();
		return os;
}
void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeSign)
		throw GradeTooLowException();
	isSigne = true;
}
Form::~Form() {}
