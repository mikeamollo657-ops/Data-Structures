#include <iostream>
using namespace std;

int main() {
    int rows = 4, cols = 5;
    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparseMatrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    int compactMatrix[20][3];
    compactMatrix[0][0] = rows;
    compactMatrix[0][1] = cols;
    compactMatrix[0][2] = nonZeroCount;

    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparseMatrix[i][j] != 0) {
                compactMatrix[k][0] = i;
                compactMatrix[k][1] = j;
                compactMatrix[k][2] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    cout << "Row\tCol\tValue" << endl;
    for (int i = 0; i <= nonZeroCount; i++) {
        cout << compactMatrix[i][0] << "\t"
             << compactMatrix[i][1] << "\t"
             << compactMatrix[i][2] << endl;
    }

    return 0;
}