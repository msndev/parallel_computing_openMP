#include <stdio.h>
#include <omp.h>

int main(int argc, char** argv){
    int partial, total;

    #pragma omp parallel private(partial) shared(total)
    {
        partial = 0;
        total = 0;

        #pragma omp for
            for(int i = 1; i <= 100; i++)
            {
                partial += i*2;
            }
        #pragma omp critical
        {
                total += partial;
        }
    }
    printf("Total Sum: %d\n",total);
    return 0;
}