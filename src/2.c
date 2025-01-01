#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    long long int N, M;
    scanf("%lld %lld", &N, &M);

    if (M%N == 0) {
        printf("YA\n");
        for (int i = 0; i < N; i++){
            printf("%lld ", M/N);
        }
    } else if (N%2 == 0 && M%(N/2) == 0) {
        printf("YA\n");
        for (int i = 1; i <= N; i++){
            printf("%lld ", i + ((M - N / 2) / N) - (N / 2));
        }
    } else {
        printf("TIDAK\n");
    }

    return 0;
}
