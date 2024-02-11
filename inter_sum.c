#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i,id,nt,s=0,N;

    printf("Enter the size: ");
    scanf("%d",&N);

    int l[N];

    for(i=0;i<N;i++)
        l[i]=1;


     #pragma omp parallel shared(l) private(i,id)
    {
        int from,to;
        id=omp_get_thread_num();
        nt=omp_get_num_threads();

        from=(N/nt)*id;
        to=(N/nt)*(id+1)-1;
        if(id==nt-1)
            to=N-1;
        for(i=0;i<N;i++)
        {
            l[i]=i+1;
        }
        for(i=0;i<N;i++)
        {
            printf("\nIntermediate Sum: %d",s);
            s+=l[i];

        }
    }

    printf("\nSum is %d",&s);

}