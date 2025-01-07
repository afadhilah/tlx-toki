#include <stdio.h>

// Fungsi untuk menghitung kombinasi C(k, n) = n! / (k! * (n-k)!)
long long comb(int n, int k) {
    if (n < k) return 0;
    long long result = 1;
    for (int i = 1; i <= k; i++) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

int main() {
    int N;
    scanf("%d", &N);

    // Baca koordinat pasak (diabaikan karena tidak ada tiga pasak yang kolinear)
    int x, y;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
    }

    // Hitung jumlah cara memilih 3 pasak
    long long result = comb(N, 3);
    printf("%lld\n", result);

    return 0;
}
