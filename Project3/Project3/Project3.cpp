#include <iostream>
#include <vector>

using namespace std;

int get(vector<int>& matrix, int i, int j, int column) {
    
    if ((i + j) % 2 == 0) {

        return 1;
    }

    int odd = 0;
    int n;

    for (int k = 0; k < i; ++k) {
        for (n = 0; n < column; ++n) {
            if ((k + n) % 2 != 0) {

                ++odd;
            }
        }
    }

    for (n = 0; n < j; ++n) {
        if ((i + n) % 2 != 0) {

            ++odd;
        }
    }

    return matrix[odd];
}


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

    int oddNum = 0;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if ((i + j) % 2 != 0) {

                ++oddNum;
            }
        }
    }

    vector<int> matrix(oddNum, 0);

    int odd = 0;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if ((i + j) % 2 != 0) {

                cout << "Enter matrix[" << i << "][" << j << "]: ";
                cin >> matrix[odd];
                ++odd;
            }
        }
    }

    cout << "Matrix:\n";
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {

            cout << get(matrix, i, j, column) << ",   ";
        }

        cout << "\n";
    }

    bool rowsWithNull = false;
    
    for (int i = 0; i < row; ++i) {

        bool hasNull = false;
        for (int j = 0; j < column; ++j) {
            if (get(matrix, i, j, column) == 0) {

                hasNull = true;
                break;
            }
        }

        if (hasNull) {

            rowsWithNull = true;
            int sum = 0;

            for (int j = 0; j < column; ++j) {

                sum += get(matrix, i, j, column);
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
            
            int cell = get(matrix, i, j, column);

            bool minimumInRow = true;
            for (int m = 0; m < column; ++m) {
                if (get(matrix, i, m, column) < cell) {
                     
                    minimumInRow = false;
                    break;
                }
            }

            if (!minimumInRow) continue;

            bool maximumInColumn = true;
            for (int m = 0; m < row; ++m) {
                if (get(matrix, m, j, column) < cell) {

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
