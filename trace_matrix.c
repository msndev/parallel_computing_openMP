#include <stdio.h>
#include <omp.h>

int main()
{
    int a[3][3]={1,3,2,8,9,6,7,4,10};
    int i,j;
    printf("18BCE0559 Sreenitya Mandava");
    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
            printf("%d\t",a[i][j]);
    }
    int trace=0;
    #pragma omp parallel for private(i) shared(trace,a)         
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(i==j)
                trace=trace+a[i][j];
    printf("\nTrace of matrix is: %d",trace);

    return 0;
}