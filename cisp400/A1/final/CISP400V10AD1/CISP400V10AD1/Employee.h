#include <string>

class Employee
{
public:
	explicit Employee( std::string , std::string , int );
	void setFirstName( std::string );
	std::string getFirstName() const;
	void setLastName( std::string );
	std::string getLastName() const;
	void setMonthlySalary( int );
	int getMonthlySalary() const;
	void increaseMonthlySalary( int );
private:
	std::string firstName;
	std::string lastName;
	int monthlySalary;
};