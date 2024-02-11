#include <omp.h>
#include <stdio.h>
int main(int *argc,char *argv[])
{
    int n;
    #pragma omp parallel default(shared)
    {

        int j,tid;
        #pragma omp single
        {
            for(j=0;j<20;j++);
            n=omp_get_num_threads();
        }
        tid=omp_get_thread_num();
        printf("18BCE0559 from thread %d of %d.\n",tid,n);
    }
    return 0;

}