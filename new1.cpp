// write a program to understand structure and union
#include <iostream>
using namespace std;
struct student
{
    char name[55];
    int age , rollno;
    char gender[25]; //void printinfo
}e1;
int main()
{
    student arr[5];
    cout << "Enter the name of the student: \n";
    cin >> e1.name;
    cout << "Enter the age of the student : \n";
    cin>> e1.age;
    cout << "Enter the gender : \n";
    cin>> e1.gender;
    cout << "name\n"<<e1.name<<endl;
     cout << "age\n"<<e1.age<<endl; 
     cout << "gender\n"<<e1.gender<<endl;
    return 0;
}
