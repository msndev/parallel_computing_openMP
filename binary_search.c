#include<stdio.h>
#include<math.h>
#include<omp.h>

void main()
{
 int sep[20],array[20],key,i,j,n=2,left,right,size,interval,index,break_value=0,tid;
 printf("Enter the size of array: ");
 scanf("%d",&size);
 printf("\nEnter the elements of array in ascending order: ");
 for(i=0;i<size;i++)
  {
   scanf("%d",&array[i]);
  }
 printf("\nEnter the key to be searched: ");
 
 scanf("%d",&key);

 left=0;
 right=size-1;
 printf("\n");

 if(key>=array[left] && key<=array[right])
  {
   while(left!=right)
   {
     printf("left=%d, right=%d, size=%d\n",left,right,size);
     if(size<=n)
      {
       #pragma omp parallel for num_threads(size)
       for(i=0;i<size;i++)
        {
         sep[i]=left+i;
         tid=omp_get_thread_num();
         printf("\nThread %d allocated sep[%d]=%d\n",tid,i,sep[i]);
        }
      }

     else
      {
       sep[0]=left;
       interval=ceil((float)size/(float)n);

       #pragma omp parallel for num_threads(n-1)
       for(i=1;i<=n-1;i++)
        {
         sep[i]=left+interval*i-1;
         tid=omp_get_thread_num();
         printf("Thread %d allocated sep[%d]=%d\n",tid,i,sep[i]);
        }

        sep[n]=right;
       }

      for(i=0;i<=n;i++)
       {
         if(key==array[sep[i]])
          {
            index=sep[i];
            printf("\nElement found at position %d\n",index+1);
            break_value=1;
            break;
          }
         if(key<array[sep[i]])
          {
            right=sep[i];
            if(i!=0)
              left=1+sep[i-1];
            size=right-left+1;
            break;
          }
       }


      if(break_value==1)
        break;
   }
  }
if(left==right || !(key>=array[left] && key<=array[right]))
  printf("Element does not present in the list\n");

printf("\n-----18BCE0559-----");
}