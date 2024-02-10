// write a code in c++ of structure without any class declarationprogram may based on simple input output understanding of keyword using
#include <iostream>
using namespace std;

struct employee
{
    int id;
    string name;
    float salary;
};

int main()
{
    employee e1;
    cout << "\nEnter the name of the employee:\n";
    getline(cin, e1.name);
    cout << "\nEnter the id of employee:\n";
    cin >> e1.id;
    cout << "\n Enter the salary of the employee: \n";
    cin >> e1.salary;
    cout << "The name of the employee is: " << e1.name << "\nThe id of the employee is: " << e1.id << "\nThe salary of the employee is: " << e1.salary;
    return 0;
}
 
