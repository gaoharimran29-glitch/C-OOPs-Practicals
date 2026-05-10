#include <iostream>
#include <algorithm>
using namespace std;

// this only works if the array is sorted
int main() {
    int arr[] = {10,20,30,40,40,50,50};
    int size = sizeof(arr) / sizeof(arr[0]); //7

    cout << "Original Array Size" << size << endl;

    sort(arr, arr + size); // sort the array

    int j = 0;

    // Why size-1 ? because we are comparing arr[i] with arr[i+1]
    for (int i = 0; i < size-1; i++) { //0,5
        if (arr[i] != arr[i+1]) {
            arr[j] = arr[i];
            j++;
        }
    }

    // Copy the last element of the array to the end of the new array
    // Last element is always unique because we are comparing arr[i] with arr[i+1]
    arr[j] = arr[size-1]; //50
    j++;

    cout << "Array Size after removing duplicates" << j <<  endl;

    cout << "Array after removing duplicates" << endl;
    for ( int k = 0 ; k < j; k++) {
        cout << arr[k] << " ";
    }
}