#include <omp.h>
#include <stdio.h>
#define N 20

main(int argc, char *argv[])
{
    int i;
    int a[N], b[N], c[N], d[N];
    for (i=0; i < N; i++)
    {
            a[i] = i * 1;
            b[i] = i + 2;
    }
    #pragma omp parallel shared(a,b,c,d) private(i)
    {
        #pragma omp sections nowait
        {
            #pragma omp section
            for (i=0; i < N; i++)
            {
                c[i] = a[i] + b[i];
                printf("%d ",c[i]);
            }
            #pragma omp section
            for (i=0; i < N; i++)
            {
                if(i==0)
                    printf("\n");
               d[i] = a[i] * b[i];
               printf("%d ",d[i]);
            }
        }

    }

}