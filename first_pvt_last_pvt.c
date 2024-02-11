#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int main(void)
{
    int var = 100;
    printf("\nFirst Private\n");
    printf("\nBefore parallelism, var's address is %p\n", &var);

    #pragma omp parallel for firstprivate(var)
    for (int i = 0; i < 4; i++)
    {
        printf("var's address in thread %d is %p, value is %d\n", omp_get_thread_num(), &var, var);
        var = i;
    }

    printf("After parallelism, var's address is %p, and value is %d\n", &var, var);


    printf("\nLast Private\n");
    printf("\nBefore parallelism, var's address is %p\n", &var);

    #pragma omp parallel for lastprivate(var)
    for (int i = 0; i < 4; i++)
    {
        printf("var's address in thread %d is %p, value is %d\n", omp_get_thread_num(), &var, var);
        var = i;
    }

    printf("After parallelism, var's address is %p, and value is %d\n", &var, var);
    return 0;
}