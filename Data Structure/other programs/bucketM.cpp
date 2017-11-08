#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *Next;
};



void Insert(int Value, struct Node **start)//1100(address of buckrt[0]),1100(address of buckrt[0])
{
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = Value;//90//80
	temp->Next = NULL;

	if(*start == NULL)//*(1100)==NULL or not?
	{
		*start = temp;
	}else
	{
	 struct Node *curr = *start;

		while(curr->Next != NULL)
		{
			curr = curr->Next;
		}
		curr->Next = temp;
	}
}


int biggestElement(int arr[],int size)
{
    int temp=arr[0];
    int length=0;
    int i;
    for(i=0;i<size;i++)
    {
     if(temp<arr[i])
     {
         temp=arr[i];

     }
    }
    while(temp>0)
    {
     temp=temp/10;
     length=length+1;

    }
return length;
}


 void radixSort(int arr[],int size)
{
   int length=biggestElement(arr,size);
    struct Node *bucket[10];
    struct Node *Temp[10];
    int i,j;

    int m=10;
    int n=1;
   int count=0;
   while(count!=length)
   {

   		for(i=0;i<10;i++)
    	{
        	bucket[i]=NULL;
        	Temp[i]=NULL;
  		}

    	for(j=0;j<size;j++)//size=4
    	{
        	int num = arr[j];//num=90,80,100////num=90,80,1///num=100
        	int mod = num%m;//mod=0,0,0///
        	int numToSave=mod/n;//0,,0,0

       		Insert(num, &bucket[numToSave]);//num=90,address of buckrt[0],80,address of buckrt[0],num=100,
    	}

    	j=0;

    	for(i=0; i<10; i++)
    	{
    		Temp[i] = bucket[i];

    		if(Temp[i] != NULL)
    		{
    			while(Temp[i]->Next != NULL)
    			{
    				arr[j] = Temp[i]->data;
    				Temp[i] = Temp[i]->Next;
    				j++;
				}
				arr[j] = Temp[i]->data;
				j++;
			}

		}

    	m=m*10;
    	n=n*10;

    	count++;
   }

   int z;
   for(z=0; z<size; z++)
   {
   		printf("\n%d",arr[z]);
   }

}


int main()
{
   int arr[]={90,80,100,1};
  int n=sizeof(arr)/sizeof(int);
  //int n=7;
   radixSort(arr,n);

    return 0;
}
