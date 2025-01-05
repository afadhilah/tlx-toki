#include <stdio.h>
#include "KompetitifDasar/01/header.h"

int main() {
    printf("Memanggil fungsi main:\n\n");

    // Memanggil fungsi dari file lain
    printf("01. Perkenalan Pemrograman Kompetitif\n");
    printf("A. Perkenalan Soal Implementasi\n");
    FungsiA();

    printf("P1. Operasi Matriks\n");
    FungsiP1();

    printf("P2. Runtuh\n");
    FungsiP2();

    printf("P3. Menyelidiki Pesan\n");
    FungsiP3();

    printf("P4. Pola String\n");
    FungsiP4();
    
    return 0;
}
