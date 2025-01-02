#include <stdio.h>

int main(){
    int M, N;

    scanf("%d %d", &M, &N);
    int inputan[M][N];

    for (int i = 0; i <= M-1; i++)
    {
        for (int j = 0; j <= N-1; j++)
        {
            scanf("%d", &inputan[i][j]);
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