#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
	int data;
	int index;
	struct Node *next;
};

void insert(struct Node**,int);
int Maximum_Digit_No(int,int []);
void ShellSort(int,int,int []);

int main()
{
	int arr[]={9,179,139,38,10,5,36};
	int Length=sizeof(arr)/sizeof(int);
	int value=Maximum_Digit_No(Length,arr);
	ShellSort(value,Length,arr);
		int t;
		for(t=0;t<Length;t++)
		{
			printf("%d \n",arr[t]);
		}
	return 0;
}

void insert(struct Node **start,int value)
{
	struct Node *temp;
	
  	temp=(struct Node*)malloc(sizeof(struct Node));
  	temp->data=value;
  	temp->next=NULL;
  	if(*start==NULL)
  	{
	   temp->index=0;
	   *start=temp;
	}
  	else
  	{
	  struct Node *current;
  	  current=*start;
	 while(current->next!=NULL)
	 	{ 
		 	current=current->next;
		} 
		int t=current->index;
		t++;
		temp->index=t;
		current->next=temp;
	
		
	}
}

int Maximum_Digit_No(int Length,int arr[])
{
	
	int max=arr[0];
	int i;
	for(int i=1;i<Length;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	int count=0;
	while (max>0)
	{
		max=max/10;
		count++;
	}
	return count;
}

void ShellSort(int digits ,int length, int *arr)
{
	struct Node *List[10];
	int i;
	int j;
	int k;
	

	for(i=0;i<digits;i++)
	{
		for(k=0;k<10;k++)
		{
			List[k]=NULL;
		}
	
	
		for(j=0;j<length;j++)
		{
			int index=(arr[j]/((int)pow((double)10,i)))%10;
		//	printf("%d \n",index);
			insert(&List[index],arr[j]);
		}
		
		int l;
		int ind=0;
		for(l=0;l<10;l++)
		{
			
			while(List[l]!=NULL)
			{
					arr[ind]=List[l]->data;
					ind++;
					List[l]=List[l]->next;
			}
		}
		
		
	}
}

