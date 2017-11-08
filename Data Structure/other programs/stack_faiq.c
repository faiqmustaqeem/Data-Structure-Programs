#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node{
	int data;
	struct Node *next;
};
//void insertAtEnd(struct Node **start,int value);
int main(int argc, char *argv[]) {
	
	struct Node *top=NULL;
	Enqueue(&top,1);
//	Enqueue(&top,2);
//	Enqueue(&top,3);
//	Enqueue(&top,4);
	return 0;
}

void EnQueue(struct Node **top,int value)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=value;
	temp->next=NULL;
	if(*top==NULL)
	{
		*top=temp;
	}
	else {
	  insertAtEnd(top,value);
	}
	
}
int DeQueue(struct Node **top)
{
	int value=0;
	if((*top!=NULL))
	{
		value=(*top)->data;
		struct Node *curr=*top;
		*top=(*top)->next;
		 free(curr);
	}
	return value;
	
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

