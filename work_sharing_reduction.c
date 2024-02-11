#include <omp.h>
#include <stdio.h>
int main ()
{
  int   i, n, chunk;
  float a[100];
  float result;
  n = 100;
  chunk = 10;
  result = 0.0;
  for (i=0; i < n; i++) {
      a[i] = i * 3.0;
  }
  #pragma omp parallel for reduction(+:result)

       for (i=0; i < n; i++)
        result += a[i];

    printf("Final result= %f\n",result);
return 0;
}