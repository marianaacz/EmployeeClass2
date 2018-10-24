#include "employee.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
   ofstream of;
   ifstream iff;
   string filename;
   int answer;
 
   cout << "This program has two options:" << endl;
   cout << "1 - Create a data file, or" << endl;
   cout << "2 - Read data from a file and print paychecks." << endl;
   cout << "Please enter (1) to create a file or (2) to print checks:" << endl;
   cin >> answer;
   
  while(true) {
      if (answer == 1) {
         cout << "Please enter a file name:" << endl;
         cin >> filename;
         of.open(filename);
         employee object1(37, "Joe Brown", "123 Main St.", "123-6788", 45.00, 10.00);
         employee object2(21, "Sam Jones", "45 East State", "661-9000", 30.00, 12.00);
         employee object3(15, "Mary Smith", "12 High Street", "401-8900", 40.00, 15.00);
         object1.write(of);
         object2.write(of);
         object3.write(of);
         of.close();
      
         if (filename == "employee.dat") {
            cout << "Data file created ... you can now run option 2." << endl;
            cin >> answer;
            if (cin.eof()) {
               break;
            }
            cout << "This program has two options:" << endl;
            cout << "1 - Create a data file, or" << endl;
            cout << "2 - Read data from a file and print paychecks." << endl;
            cout << "Please enter (1) to create a file or (2) to print checks:";     
         }
         else 
         cout << "Couldn't open file for input" << endl;
      }
   
      else if (answer == 2) {
         cout << "Please enter a file name:" << endl;
         cin >> filename;
         iff.open(filename);  
         if (filename == "employee.dat") {
            employee object1 = object1.read(iff);
            employee object2 = object2.read(iff);
            employee object3 = object3.read(iff);
            object1.printCheck();
            object2.printCheck();
            object3.printCheck();  
            break;
         }
         else 
         cout << "Couldn't open file for input" << endl;
         break;
         } 
   }
   cout << endl;
   
	cin.ignore();
	cin.get();
	return 0;
}
