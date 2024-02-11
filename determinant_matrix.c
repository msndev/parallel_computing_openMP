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
    int det=0;
    #pragma omp parallel for private(i) shared(det,a)         
    for(i=0;i<3;i++)
        det = det + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3]-a[1][(i+2)%3]*a[2][(i+1)%3]));
    printf("\nDeterminant of matrix is: %d",det);

    return 0;
}