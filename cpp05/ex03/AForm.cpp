#include "AForm.h"
#include "Bureaucrat.h"

AForm::AForm(const std::string& name, int gradeSign, int gradeExcute) : 
	name(name), 
	gradeSign(gradeSign), 
	isSigned(false),
	gradeExcute(gradeExcute)
{
	if (gradeSign < 1 || gradeExcute < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExcute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : 
	name(other.name), 
	gradeSign(other.gradeSign), 
	isSigned(other.isSigned), 
	gradeExcute(other.gradeExcute){}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
		isSigned = other.isSigned;
    }
    return (*this);
}

const std::string& AForm::getName() const
{
	return name;
}

bool AForm::isSigne() const 
{
	return isSigned;
}

int AForm::gradeToSign() const
{
	return gradeSign;
}

int AForm::gradeToExcute() const
{
	return gradeExcute;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm Grade Too Low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is Not Signed ";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm " << form.getName()
		<< " , Signed: " << form.isSigne()
		<< " , grade to signe: " << form.gradeToSign()
		<< " , grade to Execute: " << form.gradeToExcute();
		return os;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeSign)
		throw GradeTooLowException();
	isSigned = true;
}
void AForm::action() const
{
	std::cout << "bull shit  :  acction doesn't work here \n";
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeExcute)
		throw GradeTooLowException();
	action();
}
AForm::~AForm() {}
