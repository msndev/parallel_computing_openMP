#include <stdio.h> #include <stdlib.h> #include <omp.h> void main()
{
int sum=0;
int lsum=0;
int A[8]={1,2,3,4,5,6,7,8}; printf("\n-----Sree Nitya-----\n", sum); printf("\n-----18BCE0559-----\n", sum);
#pragma omp {
int i; #pragma for
parallel private(lsum)
omp for
(i=0; i<8; i++)
#pragma {
omp critical
{
lsum = lsum +A[i];
print("Intermediate Sum: %d\n,lsum"); }
sum+=lsum;
} }
printf("Sum: %d", sum); }