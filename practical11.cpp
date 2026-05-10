#include <iostream>
#include <fstream>
using namespace std;

class Student {

    int rollNo;
    char name[50];
    char studentClass[20];
    int year;
    float totalMarks;

public:

    // Input Student Data
    void input() {

        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Name: ";
        cin.getline(name, 50);

        cout << "Enter Class: ";
        cin.getline(studentClass, 20);

        cout << "Enter Year: ";
        cin >> year;

        cout << "Enter Total Marks: ";
        cin >> totalMarks;
    }

    // Display Student Data
    void display() {

        cout << "\nRoll Number : " << rollNo << endl;
        cout << "Name        : " << name << endl;
        cout << "Class       : " << studentClass << endl;
        cout << "Year        : " << year << endl;
        cout << "Total Marks : " << totalMarks << endl;
    }
};

int main() {

    Student s;

    // Create output file
    ofstream outFile("students.dat", ios::binary);

    // Store 5 student objects
    cout << "Enter Details of 5 Students" << endl;

    for (int i = 0; i < 5; i++) {

        cout << "\nStudent " << i + 1 << endl;

        s.input();

        outFile.write((char*)&s, sizeof(s));
    }

    outFile.close();

    // Read from file
    ifstream inFile("students.dat", ios::binary);

    cout << "\n\n--- STUDENT RECORDS FROM FILE ---" << endl;

    while (inFile.read((char*)&s, sizeof(s))) {

        s.display();
    }

    inFile.close();

    return 0;
}