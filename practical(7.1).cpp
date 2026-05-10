#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    int r1;
    while (b !=0 ) {
      r1 = a % b;
      a = b;
      b = r1;
   }

    cout << "GCD (without recursion): " << a << endl;
}