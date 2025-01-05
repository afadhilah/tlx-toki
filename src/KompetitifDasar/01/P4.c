#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 100

void FungsiP4() {
    char input[256] = "SeleksiTOKI2010"; // Maksimal panjang input adalah 255 karakter
    //scanf("%s", input);

    int length = (int)strlen(input); // Panjang string input
    int N = (int)ceil(sqrt(length)); // Ukuran sisi matriks terkecil

    char matrix[MAX][MAX]; // Matriks hasil
    int index = 0;     // Indeks untuk membaca karakter input

    // Isi matriks dengan karakter dari input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (index < length) {
                matrix[i][j] = input[index++];
            } else {
                matrix[i][j] = '.'; // Isi sisa dengan '.'
            }
        }
    }

    // Cetak matriks dengan baris genap terbalik
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) { // Baris ganjil (indeks genap)
            for (int j = 0; j < N; j++) {
                printf("%c", matrix[i][j]);
            }
        } else { // Baris genap (indeks ganjil)
            for (int j = N - 1; j >= 0; j--) {
                printf("%c", matrix[i][j]);
            }
        }
        printf("\n");
    }
}
