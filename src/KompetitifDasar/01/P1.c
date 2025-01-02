#include <stdio.h>

#define MAX 100

// Fungsi untuk melakukan rotasi 90 derajat searah jarum jam
void rotate90(int matrix[MAX][MAX], int *rows, int *cols) {
    int temp[MAX][MAX];
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            temp[j][*rows - i - 1] = matrix[i][j];
        }
    }
    // Menyalin hasil rotasi ke matriks asli
    for (int i = 0; i < *cols; i++) {
        for (int j = 0; j < *rows; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
    // Tukar jumlah baris dan kolom
    int tempVal = *rows;
    *rows = *cols;
    *cols = tempVal;
}

// Fungsi untuk melakukan rotasi 180 derajat
void rotate180(int matrix[MAX][MAX], int *rows, int *cols) {
    rotate90(matrix, rows, cols);
    rotate90(matrix, rows, cols);
}

// Fungsi untuk melakukan rotasi 270 derajat
void rotate270(int matrix[MAX][MAX], int *rows, int *cols) {
    rotate90(matrix, rows, cols);
    rotate90(matrix, rows, cols);
    rotate90(matrix, rows, cols);
}

// Fungsi untuk melakukan refleksi horizontal
void reflectHorizontal(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows / 2; i++) {
        for (int j = 0; j < cols; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[rows - i - 1][j];
            matrix[rows - i - 1][j] = temp;
        }
    }
}

// Fungsi untuk melakukan refleksi vertikal
void reflectVertical(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][cols - j - 1];
            matrix[i][cols - j - 1] = temp;
        }
    }
}

int main() {
    int rows, cols, X;
    int matrix[MAX][MAX];

    // Membaca input
    scanf("%d %d %d", &rows, &cols, &X);

    // Membaca elemen-elemen matriks
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Membaca operasi dan melakukan manipulasi matriks sesuai dengan operasi
    for (int i = 0; i < X; i++) {
        char operation[4];
        scanf("%s", operation);

        if (operation[0] == '_') {
            reflectHorizontal(matrix, rows, cols);
        } else if (operation[0] == '|') {
            reflectVertical(matrix, rows, cols);
        } else if (operation[0] == '9') {  // 90 derajat
            rotate90(matrix, &rows, &cols);
        } else if (operation[0] == '1') {  // 180 derajat
            rotate180(matrix, &rows, &cols);
        } else if (operation[0] == '2') {  // 270 derajat
            rotate270(matrix, &rows, &cols);
        }
    }

    // Menampilkan hasil akhir matriks
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
