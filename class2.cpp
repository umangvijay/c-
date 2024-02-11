#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    Employee(int id, float salary, const string& name) : id(id), name(name), salary(salary) {
        cout << "Employee details are :" << endl;
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    float getSalary() const {
        return salary;
    }

    void setId(int newId) {
        id = newId;
    }

    void setName(const string& newName) {
        name = newName;
    }

    void setSalary(float newSalary) {
        salary = newSalary;
    }

    void accessEmployeeInfo() {
        int newId;
        string newName;
        float newSalary;
        cout << "Enter Employee Id : ";
        cin >> newId;
        setId(newId);
        cout << "Enter employee name :";
        cin.ignore();
        getline(cin, newName);
        setName(newName);
        cout << "Enter employee salary :";
        cin >> newSalary;
        setSalary(newSalary);
    }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    vector<Employee> employees;

    for (int i = 0; i < n; ++i) {
        int id;
        float salary;
        string name;

        cout << "\nEnter details for Employee " << i + 1 << ":" << endl;
        cout << "Enter Employee Id: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Employee Salary: ";
        cin >> salary;

        employees.push_back(Employee(id, salary, name));
    }

    cout << "\nEmployee details are:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Employee " << i + 1 << " details:" << endl;
        cout << "ID: " << employees[i].getId() << ", Name: " << employees[i].getName() << ", Salary: " << employees[i].getSalary() << endl;
    }

    return 0;
}
