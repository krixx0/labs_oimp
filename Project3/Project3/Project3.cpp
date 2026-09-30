#include <iostream>
#include <vector>

using namespace std;

int main() {

    int row;
    int column;

    cout << "Enter number of rows(1 <= n <= 10): ";
    cin >> row;

    if (row > 10 || row < 1) {
        cout << "Wrong. Try again\n";
        return 0;
    }

    cout << "Enter number of columns(1 <= n <= 10): ";
    cin >> column;

    if (column > 10 || column < 1) {
        cout << "Wrong. Try again\n";
        return 0;
    }

    vector<vector<int>> matrix(row, vector<int>(column));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if ((i + j) % 2 == 0) {

                matrix[i][j] = 1;
            }

            else {

                cout << "Enter matrix[" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
    }

    cout << "Matrix:\n";
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {

            cout << matrix[i][j] << ",   ";
        }
        cout << "\n";
    }

    bool rowsWithNull = false;
    
    for (int i = 0; i < row; ++i) {

        bool hasNull = false;
        for (int j = 0; j < column; ++j) {
            if (matrix[i][j] == 0) {

                hasNull = true;
                break;
            }
        }

        if (hasNull) {

            rowsWithNull = true;
            int sum = 0;
            for (int j = 0; j < column; ++j) {

                sum += matrix[i][j];
            }

            cout << "sum of elements with 0 in row " << i + 1 << ": " << sum << "\n";
        }
    }
    if (!rowsWithNull) {

        cout << "no rows with 0 :( kva kva kvaaaa\n";
    }

    int counter = 0;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
             
            bool minimumInRow = true;
            for (int m = 0; m < column; ++m) {
                if (matrix[i][m] < matrix[i][j]) {
                     
                    minimumInRow = false;
                    break;
                }
            }
            if (!minimumInRow) continue;

            bool maximumInColumn = true;
            for (int m = 0; m < row; ++m) {
                if (matrix[m][j] > matrix[i][j]) {

                    maximumInColumn = false;
                    break;
                }
            }
            if (maximumInColumn) {

                ++counter;
            }
        }
    }

    cout << "the number of saddle points: " << counter;

	return 0;
}
