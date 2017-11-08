#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 struct Node
 {
 	int data;
 	struct Node *next;
 };
void insert(struct Node **start,int value);
void printList(struct Node *start);
void insertAtBeg(struct Node **start,int value);
void insertAtEnd(struct Node **start,int value);
void sortedInsert(struct Node **start,int value);

int main(int argc, char *argv[]) {
	
	
	
	struct Node **start=NULL;
	//insert(&start,5);
	//insert(&start,2);
	
   	sortedInsert(&start,5);
	sortedInsert(&start,2);
	sortedInsert(&start,3);
	sortedInsert(&start,1);
	sortedInsert(&start,8);
	sortedInsert(&start,25);
	//insert(&start,3);
	//insert(&start,5);
	//insert(&start,1);
	//insert(&start,2);
	//insert(&start,4);
	//insertAtBeg(&start,4);
	//insertAtEnd(&start,0);
	printList(start);
	//struct Node** temp=start;
	//(*temp)=(*temp)->next;
	
	 //printf(" %d ",((*start)->next)->data);
	//bubbleSort(&start);
	return 0;
}
void insert(struct Node **start,int value)
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
void insertAtBeg(struct Node **start,int value)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=value;
	temp->next=*start;
	*start=temp;	
}

void insertAtEnd(struct Node **start,int value)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=value;
	temp->next=NULL;
	
	struct Node *current=*start;
	while(current->next!=NULL)
	{
		current=current->next;
	}
	current->next=temp;
	
	
		
}
void sortedInsert(struct Node **start,int value)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->next=NULL;
	temp->data=value;
	
	
	//get tail of linked list
	struct Node *tail=*start;
	if((*start)!=NULL)// do not get tail if linked list is sempty
	{
	
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	}
	//end get tail
	
	if((*start)==NULL)
	{
		*start=temp;
	}
	else if(value < (*start)->data)
	{
		insertAtBeg(start,value);
	}
	else if(value > tail->data )
	{
		insertAtEnd(start,value);
	}
	else
	{
		struct Node *current=*start;
		while(value > current->next->data)
		{
			current=current->next;
		}
		temp->next=current->next;
		current->next=temp;
	}
	
	
	
}


