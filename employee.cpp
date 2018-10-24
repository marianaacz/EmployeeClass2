#include <string>
#include "employee.h"
#include<iomanip>
#include<fstream>
using namespace std;

   employee::employee()
{
	string name = "";
	
}
   employee::employee(int employeeNumber, string name, string address, string phone,  double hoursWorked, double hourlyWage) {
      this->name = name;
      this->address = address;
      this->phone = phone;
      this->employeeNumber = employeeNumber;
      this->hourlyWage = hourlyWage;
      this->hoursWorked = hoursWorked;
   }
      
double employee::calcPay(double pay, double payWT) {
   if ((hoursWorked - 40) > 0) {
      payWT = (40 * hourlyWage) + ((hoursWorked - 40) * (hourlyWage * 1.5));
      pay = (payWT - (payWT * 0.20) - (payWT *0.075));
   }
   else {
      payWT = hourlyWage * hoursWorked;
      pay = (payWT - (payWT * 0.20) - (payWT *0.075));
   }
   return pay;
}

void employee::printCheck() {
   double pay = calcPay(hourlyWage, hoursWorked);
   cout << " ....................UVU Computer Science Dept................................." << endl;
   cout << "Pay to the order of " << name << "....................................$" <<fixed<<setprecision(2)<< pay << endl; 
   cout << "United Community Credit Union" << endl;
   cout << ".............................................................................." << endl;
   cout << "Hours worked: " << hoursWorked << endl; //
   cout << "Hourly wage: " << hourlyWage << endl; //
}

void employee::write(ofstream& writeFiles) {
   writeFiles << name << "\n";
   writeFiles << address << "\n";
   writeFiles << phone << "\n";
   writeFiles << employeeNumber << "\n";
   writeFiles << hourlyWage << "\n";
   writeFiles << hoursWorked << "\n";
}
   
employee employee::read(ifstream& readFiles) {
   employee employeeX;
   string temp;
   getline(readFiles, employeeX.name);
   getline(readFiles, employeeX.address);
   readFiles >> employeeX.phone;
   readFiles >> employeeX.employeeNumber;
   readFiles >> employeeX.hourlyWage;
   readFiles >> employeeX.hoursWorked;
   getline(readFiles, temp);
   return employeeX;
}
