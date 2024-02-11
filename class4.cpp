#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Class representing an Address
class Address {
private:
    string street;
    string city;
    string state;
    string zipCode;

public:
    Address(const string& street, const string& city, const string& state, const string& zipCode)
        : street(street), city(city), state(state), zipCode(zipCode) {}

    // Function to display address details
    void display() const {
        cout << "Address: " << street << ", " << city << ", " << state << ", " << zipCode << endl;
    }
};

// Class representing a Person
class Person {
private:
    string name;
    Address address;

public:
    Person(const string& name, const Address& address) : name(name), address(address) {}

    // Function to display person details
    void display() const {
        cout << "Name: " << name << endl;
        address.display();
    }
};

int main() {
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    vector<Person> people;

    for (int i = 0; i < n; ++i) {
        string name, street, city, state, zipCode;

        cout << "\nEnter details for Person " << i + 1 << ":" << endl;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Street: ";
        getline(cin, street);
        cout << "Enter City: ";
        getline(cin, city);
        cout << "Enter State: ";
        getline(cin, state);
        cout << "Enter Zip Code: ";
        getline(cin, zipCode);

        Address address(street, city, state, zipCode);
        people.push_back(Person(name, address));
    }

    cout << "\nPeople Details:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "\nDetails for Person " << i + 1 << ":" << endl;
        people[i].display();
    }

    return 0;
}
