#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// ─────────────────────────────────────────
//  CLASS : Employee
// ─────────────────────────────────────────
class Employee {
private:
    int    employee_id;
    string name;
    float  basic_salary;
    float  net_salary;

public:
    // ── Default Constructor
    Employee() {
        employee_id  = 0;
        name         = "Unknown";
        basic_salary = 0.0;
        net_salary   = 0.0;
    }

    // ── Parameterized Constructor
    Employee(int id, string n, float basic) {
        employee_id  = id;
        name         = n;
        basic_salary = basic;
        net_salary   = 0.0;
    }

    // ── Destructor
    ~Employee() {
        // No dynamic memory, but good practice to have
    }

    // ── calculateSalary()
    // Logic: Net = Basic + 20% Bonus - 10% Tax
    void calculateSalary() {
        float bonus     = 0.20 * basic_salary;
        float deduction = 0.10 * basic_salary;
        net_salary      = basic_salary + bonus - deduction;
    }

    // ── displayEmployee()
    void displayEmployee() {
        cout << "-------------------------------\n";
        cout << "  ID           : " << employee_id  << "\n";
        cout << "  Name         : " << name         << "\n";
        cout << "  Basic Salary : Rs." << basic_salary << "\n";
        cout << "  Net Salary   : Rs." << net_salary   << "\n";
        cout << "-------------------------------\n";
    }

    // ── Getters (needed for file write)
    int    getId()          { return employee_id;  }
    string getName()        { return name;         }
    float  getBasicSalary() { return basic_salary; }
    float  getNetSalary()   { return net_salary;   }

    // ── Setters (needed for file read)
    void setId(int id)             { employee_id  = id;    }
    void setName(string n)         { name         = n;     }
    void setBasicSalary(float b)   { basic_salary = b;     }
};


// ─────────────────────────────────────────
//  GLOBAL : Max employees
// ─────────────────────────────────────────
const int MAX = 20;
Employee  employees[MAX];
int       empCount = 0;


// ─────────────────────────────────────────
//  FUNCTION : Load records from file
// ─────────────────────────────────────────
void loadRecords() {
    try {
        ifstream fin("employees.txt");

        // Exception: file does not exist or cannot open
        if (!fin) {
            throw runtime_error("ERROR: Cannot open 'employees.txt'. "
                                "File not found or inaccessible.");
        }

        empCount = 0;
        int   id;
        string name;
        float basic;

        while (fin >> id >> name >> basic) {
            if (empCount >= MAX) {
                cout << "WARNING: Max limit reached. "
                        "Only first 20 records loaded.\n";
                break;
            }
            employees[empCount].setId(id);
            employees[empCount].setName(name);
            employees[empCount].setBasicSalary(basic);
            empCount++;
        }

        fin.close();
        cout << "\n" << empCount
             << " employee record(s) loaded successfully.\n";

    } catch (runtime_error& e) {
        cout << e.what() << "\n";
        cout << "HINT: Make sure 'employees.txt' exists in "
                "the same folder as this program.\n";
    }
}


// ─────────────────────────────────────────
//  FUNCTION : Calculate salary for all
// ─────────────────────────────────────────
void calculateAll() {
    if (empCount == 0) {
        cout << "\nNo records loaded. Please load records first.\n";
        return;
    }
    for (int i = 0; i < empCount; i++) {
        employees[i].calculateSalary();
    }
    cout << "\nSalary calculated for all "
         << empCount << " employee(s).\n";
    cout << "Formula: Net = Basic + 20% Bonus - 10% Tax\n";
}


// ─────────────────────────────────────────
//  FUNCTION : Save updated records to file
// ─────────────────────────────────────────
void saveRecords() {
    try {
        if (empCount == 0) {
            cout << "\nNo records to save.\n";
            return;
        }

        ofstream fout("employees_updated.txt");

        // Exception: cannot write to file
        if (!fout) {
            throw runtime_error("ERROR: Cannot write to "
                                "'employees_updated.txt'.");
        }

        fout << "ID\tNAME\t\tBASIC\t\tNET SALARY\n";
        fout << "------------------------------------------------\n";

        for (int i = 0; i < empCount; i++) {
            fout << employees[i].getId()          << "\t"
                 << employees[i].getName()        << "\t\t"
                 << employees[i].getBasicSalary() << "\t\t"
                 << employees[i].getNetSalary()   << "\n";
        }

        fout.close();
        cout << "\nRecords saved to 'employees_updated.txt'.\n";

    } catch (runtime_error& e) {
        cout << e.what() << "\n";
    }
}


// ─────────────────────────────────────────
//  FUNCTION : Display all loaded records
// ─────────────────────────────────────────
void displayAll() {
    if (empCount == 0) {
        cout << "\nNo records loaded yet.\n";
        return;
    }
    cout << "\n===== ALL EMPLOYEE RECORDS =====\n";
    for (int i = 0; i < empCount; i++) {
        employees[i].displayEmployee();
    }
}


// ─────────────────────────────────────────
//  FUNCTION : Create a sample employees.txt
//             (so program works out of box)
// ─────────────────────────────────────────
void createSampleFile() {
    ofstream fout("employees.txt");
    if (fout) {
        fout << "101 Bhanu 50000\n";
        fout << "102 Ravi 60000\n";
        fout << "103 Priya 45000\n";
        fout << "104 Amit 70000\n";
        fout << "105 Sneha 55000\n";
        fout.close();
        cout << "Sample 'employees.txt' created.\n";
    }
}


// ─────────────────────────────────────────
//  MAIN — Menu Driven
// ─────────────────────────────────────────
int main() {
    int choice;

    cout << "==========================================\n";
    cout << "   EMPLOYEE SALARY MANAGEMENT SYSTEM      \n";
    cout << "==========================================\n";

    // Auto-create sample file if it doesn't exist
    ifstream check("employees.txt");
    if (!check) {
        cout << "\n'employees.txt' not found.\n";
        cout << "Creating a sample file automatically...\n";
        createSampleFile();
    }
    check.close();

    do {
        cout << "\n--------- MAIN MENU ---------\n";
        cout << "1. Load Employee Records\n";
        cout << "2. Calculate Salaries\n";
        cout << "3. Save Updated Records\n";
        cout << "4. Display All Records\n";
        cout << "5. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch (choice) {
            case 1: loadRecords();   break;
            case 2: calculateAll();  break;
            case 3: saveRecords();   break;
            case 4: displayAll();    break;
            case 5: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}