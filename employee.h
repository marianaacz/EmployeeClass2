#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class employee
{
private:
	string name;
	string address;
	string phone;
	int employeeNumber;
	double hourlyWage;
	double hoursWorked;
public:
	employee();
	employee(int employeeNumber, string name, string address, string phone, double hoursWorked, double hourlyWage);
	double calcPay(double,double);
	void printCheck();
	employee read(ifstream&);
	void write(ofstream&);
	
};
