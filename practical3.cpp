#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main(int argc , char* argv[]) {
    int count[26] = {0};

    if (argc < 2) {
        cout << "Please enter value using command line arguement" << endl;
    }

    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0' , j++) {
            char ch = tolower(argv[i][j]);
            if (ch>='a' && ch<='z') {
                count[ch - 'a']++;
            }
        }
    }

    cout << "Alphabet occurence table" << endl;

    for (int k = 0; k < 26; k++) {
        if (count[k] > 0) {
            cout << char(ch + 'a') << "\t\t" << count[k] << endl;
        }
    }
}