#include <stdio.h>
#include <conio.h>

void shellsort(int,int []);

int main()
{
	int arr[]={6,7,5,1,2,4,-1,9,8,13,-6,28};
	int length=sizeof(arr)/4;
	shellsort(length,arr);
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d \n",arr[i]);
	}
	
	return 0;	
}

void shellsort(int length,int *arr)
{
	int gap=length/2;
	while(gap>0)
	{
		int i;
		int j;
		for(i=gap;i<length;i=i+gap)
		{
			for(j=i;j>0;j=j-gap)
			{
				if(arr[j]<arr[j-gap])
				{
					int temp=arr[j];
					arr[j]=arr[j-gap];
					arr[j-gap]=temp;
				}
			}
		}
	
     	gap=gap/2;
	}
	
}
