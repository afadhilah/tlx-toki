#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_N 1000000   // Estimasi batas atas untuk bilangan prima ke-77,777
#define MAX_PRIMES 77777 // Jumlah maksimum bilangan prima yang dibutuhkan

void generate_primes(int primes[], int *count) {
    bool is_prime[MAX_N + 1];
    for (int i = 0; i <= MAX_N; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = is_prime[1] = false; // 0 dan 1 bukan bilangan prima

    for (int i = 2; i <= sqrt(MAX_N); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    *count = 0;
    for (int i = 2; i <= MAX_N && *count < MAX_PRIMES; i++) {
        if (is_prime[i]) {
            primes[(*count)++] = i;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    int queries[T];
    for (int i = 0; i < T; i++) {
        scanf("%d", &queries[i]);
    }

    int primes[MAX_PRIMES];
    int prime_count = 0;

    // Generate primes
    generate_primes(primes, &prime_count);

    // Answer queries
    for (int i = 0; i < T; i++) {
        printf("%d\n", primes[queries[i] - 1]);
    }

    return 0;
}
