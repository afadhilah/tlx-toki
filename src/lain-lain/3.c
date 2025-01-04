#include <stdio.h>

int main() {
    int N, c, a, b;
    
    // Membaca input
    scanf("%d", &N);
    // Membaca posisi pertama dan inisialisasi a dan b
    scanf("%d", &c);
    a = b = c;
    
    // Membaca posisi semut dan mencari nilai maksimum dan minimum
    for (int i = 1; i < N; i++) {
        scanf("%d", &c);
        if (c > a) a = c;
        if (c < b) b = c;
    }

    // Output titik tengah
    printf("%d\n", (a + b) / 2);
    
    return 0;
}
