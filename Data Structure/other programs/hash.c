#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 struct Node
 {
 	int data;
 	struct Node *next;
 };
void insertInt(struct Node **start,int value);
void insertChar(struct Node **start,char value);
void printList(struct Node *start);
int hashFunction(int value);
int searchInt(struct Node *start[], int vts);
int search(struct Node *start[], int vts);
int main(int argc, char *argv[]) {
	
	
	
	
	int intArray[]={'x','z','r','b','a'};
	struct Node *array[10];
	int i;
	for(i=0 ; i < 10 ; i++)
	{
		array[i]=NULL;
	}
	for( i = 0; i < 10; i++ )
	{
		int index=hashFunction(intArray[i]);
		char value=intArray[i];
		insertChar(&array[index],value);
	}
	int found=search(array,'g');
	 printf(" %d ",found);
	return 0;
}     
int searchInt(struct Node *start[], int vts)
{
	int index=hashFunction(vts);
	
	while((start[index])->next!=NULL)
	{
		if(start[index]->data==vts)
		{
			return 1;
		}
		start[index]=start[index]->next;
	}
	
}
int searchChar(struct Node *start[], char vts)
{
	int index=hashFunction(vts);
	
	while((start[index])->next!=NULL)
	{
		if(start[index]->data==vts)
		{
			return 1;
		}
		start[index]=start[index]->next;
	}
	
}
int hashFunction(int value)
{
	return (value%10);
}

void insertInt(struct Node **start,int value)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->next=NULL;
	temp->data=value;
	
	
	if((*start)==NULL)
	{
		*start=temp;
	}
	else
	{
		struct Node *current=*start;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=temp;
	}
	
}
void insertChar(struct Node **start,char value)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->next=NULL;
	temp->data=value;
	
	
	if((*start)==NULL)
	{
		*start=temp;
	}
	else
	{
		struct Node *current=*start;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=temp;
	}
	
}
void printList(struct Node *start)
{
	printf("\n");
	struct Node *temp=start;
	while(temp!=NULL)
	{
		printf(" %d ",temp->data);
		temp=temp->next;
	}

}


