#include <iostream>
using namespace std;

class employee {
private:
    int id;
    double salary;
    string name;

public:
    employee(int id, const string& name, double salary): id(id), name(name), salary(salary) {}

    int getid() const {
        return id;
    }

    string getname() const {
        return name;
    }

    double getsalary() const {
        return salary;
    }

    void setid(int id) {
        this->id = id;
    }

    void setname(const string& name) {
        this->name = name;
    }

    void setsalary(double salary) {
        this->salary = salary;
    }

    void displayinfo() const {
        cout << "Employee id: " << id << ", Employee name: " << name << ", Employee salary: " << salary << endl;
    }
};

void accessemployeeinfo(employee& emp) {
    int id;
    double salary;
    string name;

    cout << "Enter Employee id: ";
    cin >> id;
    emp.setid(id);

    cout << "Enter employee name: ";
    cin.ignore();
    getline(cin, name);
    emp.setname(name);

    cout << "Enter employee salary: ";
    cin >> salary;
    emp.setsalary(salary);
}

int main() {
    employee emp1(1, "John doh", 50000);
    employee emp2(2, "xyz", 60000);
    cout << "Enter the employee numbers you want require";
    cout << "Employee information after setting new salary" << endl;
    emp1.displayinfo();

    cout << "\nEmployee information before modification" << endl;
    emp2.displayinfo()<< endl;

    cout << "\nEnter details for modifying employee information:" << endl;
    accessemployeeinfo(emp2);

    cout << "\nEmployee information after modification" << endl;
    emp2.displayinfo();

    return 0;
}
