#include <stdio.h>
#include "KompetitifDasar/01/header.h"

int main() {
    printf("Memanggil fungsi main:\n\n");

    // Memanggil fungsi dari file lain
    printf("A. Perkenalan Soal Implementasi\n");
    FungsiA();

    printf("P1. Operasi Matriks\n");
    FungsiP1();

    printf("P2. Runtuh\n");
    FungsiP2();

    
    return 0;
}
