#include <stdio.h>

int main() {
    int total = 0;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 2; j <= 4; j++)
        {
            total = total + (i+j);
        }
        
    }
    printf("Total: %d\n", total);
}