#include <iostream>
#include <iomanip>

double** createMatrix(int rows, int cols) {
    double** matrix = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
    }
    return matrix;
}

void inputMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void generateMatrix(double** matrix, int rows, int cols, double a, double b) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = a;  // Jednostavno postavlja sve na a (npr. donju granicu)
        }
    }
}

double** addMatrices(double** A, int rows, int cols, double** B) {
    double** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

double** subtractMatrices(double** A, int rows, int cols, double** B) {
    double** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

double** multiplyMatrices(double** A, int ra, int ca, double** B, int rb, int cb) {
    double** result = createMatrix(ra, cb);
    for (int i = 0; i < ra; ++i) {
        for (int j = 0; j < cb; ++j) {
            result[i][j] = 0.0;
            for (int k = 0; k < ca; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

double** transposeMatrix(double** A, int rows, int cols) {
    double** result = createMatrix(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = A[i][j];
        }
    }
    return result;
}

void printMatrix(double** matrix, int rows, int cols) {
    std::cout << std::fixed << std::setprecision(4);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(10) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void deleteMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows = 2, cols = 2;

    double** mat1 = createMatrix(rows, cols);
    std::cout << "Unesite matricu 1 (2x2, unosite 4 broja red po red):" << std::endl;
    inputMatrix(mat1, rows, cols);

    double** mat2 = createMatrix(rows, cols);
    std::cout << "Unesite matricu 2 (2x2, unosite 4 broja red po red):" << std::endl;
    inputMatrix(mat2, rows, cols);

    std::cout << "\nMat1:" << std::endl;
    printMatrix(mat1, rows, cols);
    std::cout << "\nMat2:" << std::endl;
    printMatrix(mat2, rows, cols);

    double** sum = addMatrices(mat1, rows, cols, mat2);
    std::cout << "\nZbroj:" << std::endl;
    printMatrix(sum, rows, cols);

    double** diff = subtractMatrices(mat1, rows, cols, mat2);
    std::cout << "\nRazlika:" << std::endl;
    printMatrix(diff, rows, cols);

    double** prod = multiplyMatrices(mat1, rows, cols, mat2, rows, cols);
    std::cout << "\nUmnožak:" << std::endl;
    printMatrix(prod, rows, cols);

    double** trans = transposeMatrix(mat1, rows, cols);
    std::cout << "\nTransponirana Mat1:" << std::endl;
    printMatrix(trans, cols, rows);

    deleteMatrix(mat1, rows);
    deleteMatrix(mat2, rows);
    deleteMatrix(sum, rows);
    deleteMatrix(diff, rows);
    deleteMatrix(prod, rows);
    deleteMatrix(trans, cols);

    return 0;
}
