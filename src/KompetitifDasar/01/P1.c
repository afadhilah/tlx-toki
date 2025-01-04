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

int FungsiP1() {
    int rows = 3, cols = 3, X = 2;
    int matrix[MAX][MAX];

    // Membaca input
    //scanf("%d %d %d", &rows, &cols, &X);
    int isi[100] = {1,2,3,4,5,6,7,8,9};

    // Membaca elemen-elemen matriks
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //scanf("%d", &matrix[i][j]);
            matrix[i][j] = isi[i*cols+j];
        }
    }

    // Membaca operasi dan melakukan manipulasi matriks sesuai dengan operasi
    char operation[2] = {'_', '2'};
    for (int i = 0; i < X; i++) {
        //scanf("%s", operation);

        if (operation[i] == '_') {
            reflectHorizontal(matrix, rows, cols);
        } else if (operation[i] == '|') {
            reflectVertical(matrix, rows, cols);
        } else if (operation[i] == '9') {  // 90 derajat
            rotate90(matrix, &rows, &cols);
        } else if (operation[i] == '1') {  // 180 derajat
            rotate180(matrix, &rows, &cols);
        } else if (operation[i] == '2') {  // 270 derajat
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
