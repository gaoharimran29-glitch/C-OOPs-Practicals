#include <iostream>
#include <cstdlib>
using namespace std;

long long factorial(int num) {
    long long fact = 1;

    for (int i = 2; i < num+1; i++) {
        fact *= i;
    }
    return fact;
}

int main(int argc , char* argv[]) {
    int n;

    if (argc > 1) {
        n = atoi(argv[1]);
    }

    else {
        cout << "Enter value of n: " << endl;
        cin >> n;
    }

    double sum = 0.0;

    for (int j = 1; j < n+1; j++) {
        if (j % 2 == 0) {
            sum -= 1.0/factorial(j);
        }
        else {
            sum += 1.0/factorial(j);
        }
    }

    cout << "Sum of the series will be: " << sum << endl;
}