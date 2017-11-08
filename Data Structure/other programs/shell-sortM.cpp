#include <stdio.h>
#include <stdlib.h>

void shellSort(int arr[],int length)
{
    int gap=length/2;
    int j=1;
    int end;
    int count=0;
   while(gap>=1)
   {
    while(count!=j)
    {
       j=0;
       end=gap;
       count=0;
        while(end!=length)
        {
            if(arr[j]<arr[j+gap])
            {
                j++;
                count++;
                end=j+gap;
            }
            else
            {
                int temp=arr[j];
                arr[j]=arr[j+gap];
                arr[j+gap]=temp;
                j++;
                end=j+gap;
            }
        }
    }
   gap=gap/2;
   count=0;
}
int z;
  for(z=0;z<length;z++)
  {
      printf("%d\n",arr[z]);
  }
}


int main()
{
   int arr[]={78,88,20,25,30,89,55,60,10,0};
   int n=sizeof(arr)/sizeof(int);
   shellSort(arr,n);

    return 0;
}
