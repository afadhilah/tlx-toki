#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
  int N, M, prima;

  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &M);

    prima = 0;
    if (M==1)
    {
      printf("YA\n");
      continue;
    }
    
    for (int j = 2; j < M; j++)
    {
      if (M%j==0)
      {
        prima++;
      }
      if (prima > 2)
      {
        break;
      }
      
    }

    if (prima <= 2)
    {
      printf("YA\n");
    }
    else
    {
      printf("BUKAN\n");
    }
    
  }
  
}