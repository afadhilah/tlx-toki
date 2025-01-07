#include <stdio.h>

int fungsi(int *n, int i){
    printf("%d", i);
    int pangkat = 0;
    while (*n%i==0)
    {
        pangkat++;
        *n /= i;
    }
    if (pangkat>1)
    {
        printf("^%d", pangkat);
    }
    if (*n>1)
    {
        printf(" x "); 
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        if (n%i==0)
        {
            fungsi(&n,i);
        }
        
    }
    
}