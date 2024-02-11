#include <stdio.h>
#include <omp.h>

int main()
{
     int l=0, u=50, s=2, i;
     #pragma omp parallel for ordered schedule(dynamic)
     for (i=l; i<u; i+=s)
     {
        #pragma omp ordered
        printf(" %d\n", i);
     }
     return 0;
}