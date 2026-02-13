#include <iostream>
#include "Employee.h"

Employee::Employee(std::string firstName, std::string lastName, int monthlySalary)
{
}

void Employee::setFirstName(std::string firstName)
{
	firstName = firstName;
}

std::string Employee::getFirstName() const
{
	return firstName;
}

void Employee::setLastName(std::string lastName)
{
	lastName = lastName;
}

std::string Employee::getLastName() const
{
	return lastName;
}

void Employee::setMonthlySalary(int monthlySalary)
{
	if (monthlySalary <= 0) monthlySalary = 1000;
	std::cout << "XX Employee: " << firstName << lastName << "'s inputted monthly salary is " << monthlySalary;
	std::cout << "** The salary is to " << monthlySalary << " **";
}

int Employee::getMonthlySalary() const
{
	return monthlySalary;
}

void Employee::increaseMonthlySalary(int rate)
{
	std::cout << "---Employee: " << firstName << lastName 
		<< "has a salary adjustment of " << rate << "%" << std::endl;
	monthlySalary = monthlySalary + (monthlySalary * rate / 100);
	std::cout << "The original monthly salary is  " << monthlySalary << std::endl;
	std::cout << "The new monthly salary is  " << monthlySalary << std::endl;
}
