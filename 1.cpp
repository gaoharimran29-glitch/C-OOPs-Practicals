#include<iostream>
#include<string>
using namespace std;

class Student {
protected:
    int    roll_number;
    string name;
    float  marks[5];

public:
    Student() {
        roll_number = 0;
        name        = "Unknown";
        for (int i = 0; i < 5; i++)
            marks[i] = 0.0;
    }

    Student(int roll) {
        roll_number = roll;
        name        = "Unknown";
        for (int i = 0; i < 5; i++)
            marks[i] = 0.0;
    }

    Student(int roll, string n, float m[]) {
        roll_number = roll;
        name        = n;
        for (int i = 0; i < 5; i++)
            marks[i] = m[i];
    }

    ~Student() {
        cout << "[Destructor] Student object for Roll No "
             << roll_number << " destroyed.\n";
    }

    void addStudent() {
        cout << "\nEnter Roll Number : "; cin >> roll_number;
        cin.ignore();
        cout << "Enter Name        : "; getline(cin, name);
        cout << "Enter marks for 5 subjects:\n";
        for (int i = 0; i < 5; i++) {
            cout << "  Subject " << (i + 1) << " : ";
            cin >> marks[i];
        }
        cout << "Student record added successfully.\n";
    }

    void addStudent(int roll, string n, float m[]) {
        roll_number = roll;
        name        = n;
        for (int i = 0; i < 5; i++)
            marks[i] = m[i];
        cout << "Student record added via arguments successfully.\n";
    }

    void modifyStudent() {
        int choice;
        cout << "\n--- Modify Student ---\n";
        cout << "1. Change Name\n";
        cout << "2. Change Marks\n";
        cout << "3. Change Both\n";
        cout << "Enter choice: "; cin >> choice;

        if (choice == 1 || choice == 3) {
            cin.ignore();
            cout << "Enter new Name: "; getline(cin, name);
        }
        if (choice == 2 || choice == 3) {
            cout << "Enter new marks for 5 subjects:\n";
            for (int i = 0; i < 5; i++) {
                cout << "  Subject " << (i + 1) << " : ";
                cin >> marks[i];
            }
        }
        cout << "Record modified successfully.\n";
    }

    void displayStudent() {
        cout << "\n==============================\n";
        cout << "  Roll Number : " << roll_number << "\n";
        cout << "  Name        : " << name        << "\n";
        cout << "  Marks       : ";
        for (int i = 0; i < 5; i++)
            cout << marks[i] << (i < 4 ? " | " : "\n");
        cout << "  Average     : " << calculateAverage() << "\n";
        cout << "==============================\n";
    }

    float calculateAverage() {
        float sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];
        return sum / 5.0;
    }

    int getRoll() { return roll_number; }
};


class UndergraduateStudent : public Student {
private:
    int year_of_study;

public:
    UndergraduateStudent() : Student() {
        year_of_study = 1;
    }

    UndergraduateStudent(int roll, string n, float m[], int yr)
        : Student(roll, n, m) {
        year_of_study = yr;
    }

    ~UndergraduateStudent() {
        cout << "[Destructor] UndergraduateStudent object destroyed.\n";
    }

    void addStudent() {
        Student::addStudent();
        cout << "Enter Year of Study (1-4): "; cin >> year_of_study;
        cout << "Undergraduate record added.\n";
    }

    void displayStudent() {
        Student::displayStudent();
        cout << "  Year of Study : " << year_of_study << "\n";
        cout << "==============================\n";
    }
};


class GraduateStudent : public Student {
private:
    string research_topic;

public:
    GraduateStudent() : Student() {
        research_topic = "Not Assigned";
    }

    GraduateStudent(int roll, string n, float m[], string topic)
        : Student(roll, n, m) {
        research_topic = topic;
    }

    ~GraduateStudent() {
        cout << "[Destructor] GraduateStudent object destroyed.\n";
    }

    void addStudent() {
        Student::addStudent();
        cin.ignore();
        cout << "Enter Research Topic: "; getline(cin, research_topic);
        cout << "Graduate record added.\n";
    }

    void displayStudent() {
        Student::displayStudent();
        cout << "  Research Topic : " << research_topic << "\n";
        cout << "==============================\n";
    }
};


int main() {
    const int MAX = 10;

    UndergraduateStudent* ugStudents[MAX] = {nullptr};
    GraduateStudent*      gStudents[MAX]  = {nullptr};

    int ugCount = 0, gCount = 0;
    int choice, type;

    cout << "========================================\n";
    cout << "   STUDENT RECORD MANAGEMENT SYSTEM     \n";
    cout << "========================================\n";

    do {
        cout << "\n--------- MAIN MENU ---------\n";
        cout << "1. Add Student\n";
        cout << "2. Display Student\n";
        cout << "3. Modify Student\n";
        cout << "4. Calculate Average\n";
        cout << "5. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch (choice) {

            case 1: {
                cout << "\nStudent Type:\n";
                cout << "1. Undergraduate\n2. Graduate\n";
                cout << "Enter type: "; cin >> type;

                if (type == 1 && ugCount < MAX) {
                    ugStudents[ugCount] = new UndergraduateStudent();
                    ugStudents[ugCount]->addStudent();
                    ugCount++;
                } else if (type == 2 && gCount < MAX) {
                    gStudents[gCount] = new GraduateStudent();
                    gStudents[gCount]->addStudent();
                    gCount++;
                } else {
                    cout << "Invalid type or max limit reached.\n";
                }
                break;
            }

            case 2: {
                cout << "\nStudent Type:\n";
                cout << "1. Undergraduate\n2. Graduate\n";
                cout << "Enter type: "; cin >> type;
                int roll;
                cout << "Enter Roll Number to search: "; cin >> roll;

                bool found = false;
                if (type == 1) {
                    for (int i = 0; i < ugCount; i++) {
                        if (ugStudents[i] != nullptr && ugStudents[i]->getRoll() == roll) {
                            ugStudents[i]->displayStudent();
                            found = true; break;
                        }
                    }
                } else {
                    for (int i = 0; i < gCount; i++) {
                        if (gStudents[i] != nullptr && gStudents[i]->getRoll() == roll) {
                            gStudents[i]->displayStudent();
                            found = true; break;
                        }
                    }
                }
                if (!found) cout << "Student not found.\n";
                break;
            }

            case 3: {
                cout << "\nStudent Type:\n";
                cout << "1. Undergraduate\n2. Graduate\n";
                cout << "Enter type: "; cin >> type;
                int roll;
                cout << "Enter Roll Number to modify: "; cin >> roll;

                bool found = false;
                if (type == 1) {
                    for (int i = 0; i < ugCount; i++) {
                        if (ugStudents[i] != nullptr && ugStudents[i]->getRoll() == roll) {
                            ugStudents[i]->modifyStudent();
                            found = true; break;
                        }
                    }
                } else {
                    for (int i = 0; i < gCount; i++) {
                        if (gStudents[i] != nullptr && gStudents[i]->getRoll() == roll) {
                            gStudents[i]->modifyStudent();
                            found = true; break;
                        }
                    }
                }
                if (!found) cout << "Student not found.\n";
                break;
            }

            case 4: {
                cout << "\nStudent Type:\n";
                cout << "1. Undergraduate\n2. Graduate\n";
                cout << "Enter type: "; cin >> type;
                int roll;
                cout << "Enter Roll Number: "; cin >> roll;

                bool found = false;
                if (type == 1) {
                    for (int i = 0; i < ugCount; i++) {
                        if (ugStudents[i] != nullptr && ugStudents[i]->getRoll() == roll) {
                            cout << "Average Marks: " << ugStudents[i]->calculateAverage() << "\n";
                            found = true; break;
                        }
                    }
                } else {
                    for (int i = 0; i < gCount; i++) {
                        if (gStudents[i] != nullptr && gStudents[i]->getRoll() == roll) {
                            cout << "Average Marks: " << gStudents[i]->calculateAverage() << "\n";
                            found = true; break;
                        }
                    }
                }
                if (!found) cout << "Student not found.\n";
                break;
            }

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    for (int i = 0; i < ugCount; i++) delete ugStudents[i];
    for (int i = 0; i < gCount; i++)  delete gStudents[i];

    return 0;
}