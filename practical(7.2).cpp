#include <iostream>
using namespace std;

int gcd(int a , int b) {
    if (b == 0) {
        return a;
    }
    return gcd (b, a%b);
}

int main() {
    int a , b;
    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;
    
    int result;
    result = gcd(a,b);

    cout << "GCD ( with recursion ): " << result << endl;
}