#include <stdio.h>

// Fungsi untuk menghitung FPB menggunakan algoritma Euclidean
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    // Deklarasi variabel
    int A, B, C, D;
    
    // Input pecahan pertama (A/B) dan pecahan kedua (C/D)
    scanf("%d %d", &A, &B);
    scanf("%d %d", &C, &D);

    // Hitung pembilang dan penyebut hasil penjumlahan
    long long E = 1LL * A * D + 1LL * C * B; // Pembilang
    long long F = 1LL * B * D;               // Penyebut

    // Sederhanakan pecahan menggunakan FPB
    long long fpb = gcd(E, F);
    E /= fpb;
    F /= fpb;

    // Output pecahan dalam bentuk paling sederhana
    printf("%lld %lld\n", E, F);

    return 0;
}
