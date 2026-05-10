#include <iostream>
using namespace std;

// Base Class
class Person {

protected:
    string name;

public:

    void getPersonData() {

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
    }

    // Virtual function for runtime polymorphism
    virtual void display() {

        cout << "Name: " << name << endl;
    }
};

// Derived Class Student
class Student : public Person {

    string course;
    int marks;
    int year;

public:

    void getStudentData() {

        getPersonData();

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Marks: ";
        cin >> marks;

        cout << "Enter Year: ";
        cin >> year;
    }

    void display() override {

        cout << "\n----- STUDENT DETAILS -----" << endl;

        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};

// Derived Class Employee
class Employee : public Person {

    string department;
    double salary;

public:

    void getEmployeeData() {

        getPersonData();

        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display() override {

        cout << "\n----- EMPLOYEE DETAILS -----" << endl;

        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {

    // Base class pointer
    Person* p;

    Student s;
    Employee e;

    int choice;

    cout << "1. Student" << endl;
    cout << "2. Employee" << endl;

    cout << "Enter Choice: ";
    cin >> choice;

    if (choice == 1) {

        s.getStudentData();

        p = &s;     // Base pointer pointing to Student object
    }

    else if (choice == 2) {

        e.getEmployeeData();

        p = &e;     // Base pointer pointing to Employee object
    }

    else {

        cout << "Invalid Choice" << endl;
        return 0;
    }

    // Runtime Polymorphism
    p->display();

    return 0;
}