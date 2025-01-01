#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Fungsi pembanding untuk qsort
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    long long A[MAX];
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &A[i]);
    }
    // Urutkan array untuk mendapatkan padi tersedikit
    qsort(A, N, sizeof(long long), compare);
    for (int i = 1; i <= N - K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[1] += A[2];
            A[2] = 0;
        }
    }

    qsort(A, N, sizeof(long long), compare);

    for (int i = 1; i <= N; i++)
    {
        printf("%lld ", A[i]);
    }

    // Hitung jumlah padi tersisa dari ⌊N/2⌋ plot tersedikit
    long long total = 0;
    for (int i = 1; i <= N / 2; i++)
    {
        total += A[i];
    }

    printf("\n%lld\n", total);
    return 0;
}
