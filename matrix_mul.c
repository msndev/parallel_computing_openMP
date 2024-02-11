#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 5
#define NUM_THREADS 5

int(*A)[N];
int(*B)[N];
int(*C)[N];


int main()
{
    int i, j, k;
    A = malloc(sizeof(int[N][N]));
    B = malloc(sizeof(int[N][N]));
    C = malloc(sizeof(int[N][N]));
    printf("\nA = \n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            A[i][j] = j+i+1;
            B[i][j] = (j+i+1)*2;
            printf("%d  ", A[i][j]);
        }
        printf("\n");
    }
    printf("\nB = \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d  ", B[i][j]);
        }
        printf("\n");
    }


    omp_set_num_threads(NUM_THREADS);

    #pragma omp parallel for private(i, j, k)
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < N; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    printf("\nA*B = \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d  ", C[i][j]);
        }
        printf("\n");
    }
}