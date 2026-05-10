#include <iostream>
using namespace std;

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int key) {

    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == key) {
        return mid;
    }

    else if (key < arr[mid]) {
        return binarySearchRecursive(arr, low, mid - 1, key);
    }

    else {
        return binarySearchRecursive(arr, mid + 1, high, key);
    }
}

// Non-Recursive Binary Search
int binarySearchIterative(int arr[], int n, int key) {

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        else if (key < arr[mid]) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;

    cout << "Enter element to search: ";
    cin >> key;

    // Recursive Search
    int result1 = binarySearchRecursive(arr, 0, n - 1, key);

    if (result1 != -1) {
        cout << "\n[Recursive] Element found at index "
             << result1 << endl;
    }
    else {
        cout << "\n[Recursive] Element not found" << endl;
    }

    // Iterative Search
    int result2 = binarySearchIterative(arr, n, key);

    if (result2 != -1) {
        cout << "[Non-Recursive] Element found at index "
             << result2 << endl;
    }
    else {
        cout << "[Non-Recursive] Element not found" << endl;
    }

    return 0;
}