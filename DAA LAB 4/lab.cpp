#include <iostream>
#include <cstring>
using namespace std;

class Employee {
    int empId;
    char *name;
    string department;
    double basicSalary;
    double *allowances;

public:
    Employee(int id, char *n, string dept, double salary, double a[]) {
        empId = id;
        department = dept;
        basicSalary = salary;

        name = new char[strlen(n) + 1];
        strcpy(name, n);

        allowances = new double[4];
        for (int i = 0; i < 4; i++)
            allowances[i] = a[i];
    }

    Employee(const Employee &e) {
        empId = e.empId;
        department = e.department;
        basicSalary = e.basicSalary;

        name = new char[strlen(e.name) + 1];
        strcpy(name, e.name);

        allowances = new double[4];
        for (int i = 0; i < 4; i++)
            allowances[i] = e.allowances[i];
    }

    double calculateGrossSalary() {
        double gross = basicSalary;

        for (int i = 0; i < 4; i++)
            gross += allowances[i];

        return gross;
    }

    void updateAllowance(int index, double value) {
        if (index >= 0 && index < 4)
            allowances[index] = value;
    }

    void updateName(char *n) {
        delete[] name;

        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void display() {
        cout << "\nEmployee ID: " << empId;
        cout << "\nName: " << name;
        cout << "\nDepartment: " << department;
        cout << "\nBasic Salary: " << basicSalary;

        cout << "\nAllowances: ";
        for (int i = 0; i < 4; i++)
            cout << allowances[i] << " ";

        cout << "\nGross Salary: " << calculateGrossSalary() << "\n";
    }

    ~Employee() {
        delete[] name;
        delete[] allowances;
    }
};

int main() {
    int id, index;
    char name[50], newName[50];
    string dept;
    double salary, allowances[4], value;

    // Input
    cout << "Enter Employee ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Department: ";
    cin >> dept;

    cout << "Enter Basic Salary: ";
    cin >> salary;

    cout << "Enter 4 Allowances (Dearness Travel Medical Book): ";
    for (int i = 0; i < 4; i++)
        cin >> allowances[i];

    Employee e1(id, name, dept, salary, allowances);

    Employee e2(e1);

    cout << "\n--- Initial Details ---";
    cout << "\nE1:";
    e1.display();

    cout << "\nE2:";
    e2.display();

    cout << "\nEnter new name for E2: ";
    cin >> newName;

    cout << "Enter allowance index (0-3) and new value: ";
    cin >> index >> value;

    e2.updateName(newName);
    e2.updateAllowance(index, value);

    cout << "\n--- After Modifying E2 ---";
    cout << "\nE1:";
    e1.display();

    cout << "\nE2:";
    e2.display();

    // 7. Create e3 by copying e2
    Employee e3(e2);

    // 8. Modify e3
    cout << "\nEnter new name for E3: ";
    cin >> newName;

    cout << "Enter allowance index (0-3) and new value: ";
    cin >> index >> value;

    e3.updateName(newName);
    e3.updateAllowance(index, value);


    cout << "\n--- After Modifying E3 ---";
    cout << "\nE1:";
    e1.display();

    cout << "\nE2:";
    e2.display();

    cout << "\nE3:";
    e3.display();

    return 0;
}