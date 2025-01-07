#include <stdio.h>

#define MOD 1000000007
#define MAXN 1000

long long fact[MAXN + 1], ifact[MAXN + 1];

// Fungsi untuk menghitung (base^exp) % MOD menggunakan eksponen modular
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Fungsi untuk prekomputasi faktorial dan invers faktorial
void precompute_factorials(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ifact[n] = mod_exp(fact[n], MOD - 2, MOD); // Modular inversi untuk n!
    for (int i = n - 1; i >= 0; i--) {
        ifact[i] = (ifact[i + 1] * (i + 1)) % MOD;
    }
}

// Fungsi untuk menghitung C(k, n) = n! / (k! * (n-k)!)
long long comb(int n, int k) {
    if (k > n || k < 0) return 0;
    return (fact[n] * ifact[k] % MOD) * ifact[n - k] % MOD;
}

int main() {
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);

    precompute_factorials(N);

    long long total = 0;
    for (int i = A; i <= B; i++) {
        total = (total + comb(N, i)) % MOD;
    }

    printf("%lld\n", total);
    return 0;
}
