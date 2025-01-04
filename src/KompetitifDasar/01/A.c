#include <stdio.h>

void FungsiA(){
    int M = 4, N = 3;

    // scanf("%d %d", &M, &N);
    int inputan[M][N];
    int isi[100] = {34,87,15,66,71,52,47,47,48,45,75,35};

    for (int i = 0; i <= M-1; i++)
    {
        for (int j = 0; j <= N-1; j++)
        {
            inputan[i][j] = isi[i*N+j];
            //scanf("%d", &inputan[i][j]);
        }
    }

    for (int i = 0; i <= N-1; i++)
    {
        for (int j = M-1; j >= 0; j--)
        {
            printf("%d ", inputan[j][i]);
        }
        printf("\n");
    }
    
}