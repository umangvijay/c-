#include <iostream>
using namespace std;

#define MAX_LENGTH 50
#define NUM_PEOPLE 3

struct Person {
    char name[MAX_LENGTH];
    int age;
    char gender;
};

int main() {
    Person people[NUM_PEOPLE];

    for (int i = 0; i < NUM_PEOPLE; ++i) {
        cout << "Enter name of person " << i + 1 << ": ";
        cin.getline(people[i].name, MAX_LENGTH);
        cout << "Enter age: ";
        cin >> people[i].age;
        cout << "Enter gender (M/F): ";
        cin >> people[i].gender;
        cin.ignore();
    }

    cout << "\nDetails of People:\n";
    for (int i = 0; i < NUM_PEOPLE; ++i) {
        cout << "Person " << i + 1 << ":\n";
        cout << "Name: " << people[i].name << endl;
        cout << "Age: " << people[i].age << endl;
        cout << "Gender: " << people[i].gender << endl;
        cout << endl;
    }

    return 0;
}
