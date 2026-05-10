#include <iostream>
using namespace std;

class Matrix {

    int rows, cols;
    int mat[10][10];

public:

    // Input Matrix
    void input() {

        cout << "Enter number of rows: ";
        cin >> rows;

        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "Enter matrix elements:" << endl;

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    // Display Matrix
    void display() {

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }

            cout << endl;
        }
    }

    // Sum of matrices
    Matrix add(Matrix m) {

        if (rows != m.rows || cols != m.cols) {
            throw "Matrix Addition Not Possible";
        }

        Matrix result;

        result.rows = rows;
        result.cols = cols;

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }

        return result;
    }

    // Product of matrices
    Matrix multiply(Matrix m) {

        if (cols != m.rows) {
            throw "Matrix Multiplication Not Possible";
        }

        Matrix result;

        result.rows = rows;
        result.cols = m.cols;

        for (int i = 0; i < result.rows; i++) {

            for (int j = 0; j < result.cols; j++) {

                result.mat[i][j] = 0;

                for (int k = 0; k < cols; k++) {

                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }

        return result;
    }

    // Transpose
    Matrix transpose() {

        Matrix result;

        result.rows = cols;
        result.cols = rows;

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                result.mat[j][i] = mat[i][j];
            }
        }

        return result;
    }
};

int main() {

    Matrix m1, m2, result;

    int choice;

    do {

        cout << "\n----- MATRIX MENU -----" << endl;
        cout << "1. Sum of Matrices" << endl;
        cout << "2. Product of Matrices" << endl;
        cout << "3. Transpose of Matrix" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        try {

            switch(choice) {

                case 1:

                    cout << "\nEnter First Matrix" << endl;
                    m1.input();

                    cout << "\nEnter Second Matrix" << endl;
                    m2.input();

                    result = m1.add(m2);

                    cout << "\nSum Matrix:" << endl;
                    result.display();

                    break;

                case 2:

                    cout << "\nEnter First Matrix" << endl;
                    m1.input();

                    cout << "\nEnter Second Matrix" << endl;
                    m2.input();

                    result = m1.multiply(m2);

                    cout << "\nProduct Matrix:" << endl;
                    result.display();

                    break;

                case 3:

                    cout << "\nEnter Matrix" << endl;
                    m1.input();

                    result = m1.transpose();

                    cout << "\nTranspose Matrix:" << endl;
                    result.display();

                    break;

                case 4:

                    cout << "Exiting Program..." << endl;
                    break;

                default:

                    cout << "Invalid Choice" << endl;
            }
        }

        catch (const char* msg) {

            cout << "\nException: " << msg << endl;
        }

    } while(choice != 4);

    return 0;
}