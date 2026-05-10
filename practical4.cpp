#include <iostream>
using namespace std;

// Function to calculate string length using pointers
int stringLength(char *str) {
    int len = 0;

    while (*(str + len) != '\0') {
        len++;
    }

    return len;
}

// a. Show address of each character
void showAddress(char str[]) {

    for (int i = 0; str[i] != '\0'; i++) {
        cout << str[i] << " -> " << (void*)&str[i] << endl;
    }
}

// b. Concatenate two strings
void concatenate(char str1[], char str2[]) {

    int i = stringLength(str1);
    int j = 0;

    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0';

    cout << "Concatenated String: " << str1 << endl;
}

// c. Compare two strings
void compareStrings(char str1[], char str2[]) {

    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {

        if (str1[i] != str2[i]) {
            break;
        }

        i++;
    }

    if (str1[i] == str2[i]) {
        cout << "Strings are Equal" << endl;
    }
    else {
        cout << "Strings are Not Equal" << endl;
    }
}

// d. Length already implemented above

// e. Convert lowercase to uppercase
void toUpperCase(char str[]) {

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }

    cout << "Uppercase String: " << str << endl;
}

// f. Reverse string
void reverseString(char str[]) {

    int len = stringLength(str);

    int start = 0;
    int end = len - 1;

    while (start < end) {

        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    cout << "Reversed String: " << str << endl;
}

// g. Insert one string into another
void insertString(char mainStr[], char insertStr[], int pos) {

    int lenMain = stringLength(mainStr);
    int lenInsert = stringLength(insertStr);

    // Shift original string right
    for (int i = lenMain; i >= pos; i--) {
        mainStr[i + lenInsert] = mainStr[i];
    }

    // Insert new string
    for (int i = 0; i < lenInsert; i++) {
        mainStr[pos + i] = insertStr[i];
    }

    cout << "Final String: " << mainStr << endl;
}

int main() {

    char str1[200], str2[100];

    int choice;

    do {

        cout << "\n----- MENU -----" << endl;
        cout << "1. Show Address of Each Character" << endl;
        cout << "2. Concatenate Two Strings" << endl;
        cout << "3. Compare Two Strings" << endl;
        cout << "4. Find Length of String" << endl;
        cout << "5. Convert Lowercase to Uppercase" << endl;
        cout << "6. Reverse String" << endl;
        cout << "7. Insert String into Another String" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        switch(choice) {

            case 1:
                cout << "Enter String: ";
                cin.getline(str1, 200);

                showAddress(str1);
                break;

            case 2:
                cout << "Enter First String: ";
                cin.getline(str1, 200);

                cout << "Enter Second String: ";
                cin.getline(str2, 100);

                concatenate(str1, str2);
                break;

            case 3:
                cout << "Enter First String: ";
                cin.getline(str1, 200);

                cout << "Enter Second String: ";
                cin.getline(str2, 100);

                compareStrings(str1, str2);
                break;

            case 4:
                cout << "Enter String: ";
                cin.getline(str1, 200);

                cout << "Length = " << stringLength(str1) << endl;
                break;

            case 5:
                cout << "Enter String: ";
                cin.getline(str1, 200);

                toUpperCase(str1);
                break;

            case 6:
                cout << "Enter String: ";
                cin.getline(str1, 200);

                reverseString(str1);
                break;

            case 7:
                int pos;

                cout << "Enter Main String: ";
                cin.getline(str1, 200);

                cout << "Enter String to Insert: ";
                cin.getline(str2, 100);

                cout << "Enter Position: ";
                cin >> pos;

                insertString(str1, str2, pos);
                break;

            case 8:
                cout << "Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid Choice" << endl;
        }

    } while(choice != 8);

    return 0;
}