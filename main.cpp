#include <iostream>
#include <vector>

using namespace std;

class SparseMatrix {

private:
    int rows, cols; // Dimensions of the sparse matrix
    vector<vector<int>> elements; // To store non-zero elements as {row, col, value}

public:
    // Constructor to initialize the sparse matrix
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    // Function to insert a non-zero element
    void insertElement(int row, int col, int value) {
        if (value == 0) {
            cout << "Cannot insert a zero value." << endl;
            return;
        }

        if (row >= rows || col >= cols || row < 0 || col < 0) {
            cout << "Invalid row or column index!" << endl;
            return;
        }
        elements.push_back({row, col, value});
    }

    // Function to display the sparse matrix
    void displayMatrix() {
        cout << "Sparse Matrix Representation (Row, Column, Value):" << endl;
        for (const auto& element : elements) {
            cout << "(" << element[0] << ", " << element[1] << ", " << element[2] << ")" << endl;
        }
    }

    // Function to display the dense matrix form
    void displayDense() {
        cout << "Dense Matrix:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                bool found = false;
                for (const auto& element : elements) {
                    if (element[0] == i && element[1] == j) {
                        cout << element[2] << " ";
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main() {

    int rows, cols, numElements;

    // Input matrix dimensions
    cout << "Enter the number of rows in the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    SparseMatrix matrix(rows, cols);

    // Input the number of non-zero elements
    cout << "Enter the number of non-zero elements: ";
    cin >> numElements;

    // Input each non-zero element
    for (int i = 0; i < numElements; ++i) {
        int row, col, value;
        cout << "Enter row index <Space> column index <Space> value for element: ( 0 0 1 ) " << i + 1 << ": ";
        cin >> row >> col >> value;
        matrix.insertElement(row, col, value);
    }

    // Display the sparse matrix and its dense form
    cout << endl;
    matrix.displayMatrix();
    cout << endl;
    matrix.displayDense();

    return 0;
}