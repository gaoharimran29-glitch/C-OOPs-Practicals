#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    
    ifstream File1("C:\\Users\\hp\\Desktop\\test\\file1.txt");

    string mytext;

    getline(File1 , mytext);

    File1.close();

    cout << mytext << endl;

    string result = "";

    for(char ch : mytext) {
        if(ch != ' ') {
            result += ch;
        }
    }

    cout << result;

    ofstream File2("C:\\Users\\hp\\Desktop\\test\\file2.txt");

    File2 << result;

    File2.close();
    
}