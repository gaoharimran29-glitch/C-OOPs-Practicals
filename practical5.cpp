#include <iostream>
using namespace std;

int main() {
    int arr1[] = {10,20,30};
    int arr2[] = {40,50,60};

    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    int merged[size1+size2];

    int j = 0;

    for (int i = 0; i < size1; i++) {
        merged[j] = arr1[i];
        j++;
    }

    for (int k = 0; k < size2; k++) {
        merged[j] = arr2[k];
        j++;
    }

    cout << "Merged Array: " << endl;
    for ( int y = 0; y < size1+size2; y++) {
        cout << merged[y] << " ";
    }

}