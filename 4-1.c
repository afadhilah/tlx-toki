#include <stdio.h>
#include <stdlib.h>

// Fungsi pembanding untuk qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b); // Urutkan secara menaik
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    long long A[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // Lakukan operasi sebanyak N-K
    for (int i = 0; i < N - K; i++) {
        long long minValue = 1e9 + 1, minIndex = -1;
        long long secondMinValue = 1e9 + 1, secondMinIndex = -1;

        // Cari dua nilai minimum dalam rentang i hingga i+K
        for (int j = i; j <= i + K && j < N; j++) {
            if (A[j] < minValue) {
                secondMinValue = minValue;
                secondMinIndex = minIndex;
                minValue = A[j];
                minIndex = j;
            } else if (A[j] < secondMinValue) {
                secondMinValue = A[j];
                secondMinIndex = j;
            }
        }

        // Transfer padi dari plot dengan nilai minimum kedua ke plot minimum
        if (minIndex != -1 && secondMinIndex != -1) {
            A[minIndex] += A[secondMinIndex];
            A[secondMinIndex] = 0;
        }
    }

    // Urutkan array secara menaik untuk mendapatkan plot tersisa dengan padi tersedikit
    qsort(A, N, sizeof(long long), compare);

    // Hitung total padi tersisa pada ⌊N/2⌋ plot tersedikit
    int halfN = N / 2;
    long long total = 0;
    for (int i = 0; i < halfN; i++) { // Ambil plot dengan padi tersedikit
        total += A[i];
    }

    printf("%lld\n", total);
    return 0;
}
