#include <stdio.h>
#include <stdlib.h>


struct NODE {
int data;
struct NODE *next;
struct NODE *prev;
};
void insert(struct NODE **start,int vti);
void printList(struct NODE *start);
void deleteAll(struct NODE **start);
int search(struct NODE *start,int vts);
void sort(struct NODE **start);
void insertionSort(struct NODE **start);
int main() {

 	
	struct NODE *start=NULL;
	insert(&start,5); 
    insert(&start,2);
	insert(&start,4);
	insert(&start,1);
	insert(&start,0);
	printList(start);

    insertionSort(&start);
	
	return 0;
}

void insert(struct NODE **start,int vti)
{
		struct NODE *temp = (struct NODE*)malloc(sizeof(struct NODE));
		temp->data=vti;
        temp->next=NULL;
        temp->prev=NULL;
		if(*start==NULL)
		{
			*start  =temp;
		}
		else
		{
			struct NODE *curr=*start;
			while(curr->next!=NULL)
			{
				curr=curr->next;
			}
			curr->next=temp;
			temp->prev=curr;
			temp->next=NULL;
		  
			
		}
			
		
		
		
}
void printList(struct NODE *start)
{
	printf("\n List is : ");
	while(start!=NULL)
	{
		printf(" %d ",start->data);
		start=start->next;
	}
}
void delete(struct NODE **start,int vtd)//vtd=value to delete
{
	
	if((*start)->data==vtd)
	{
		
		struct NODE *temp=*start;
		struct NODE *nextNode=(*start)->next;
		nextNode->prev=NULL;
		*start=(*start)->next;
		free(temp);
	}
	else
	{
		struct NODE *curr=(*start)->next;
		struct NODE *prev=*start;
		while(curr->data!=vtd)
		{
			curr=curr->next;
			prev=prev->next;

		}
		prev->next=curr->next;
		curr->prev=prev->next;
		free(curr);
		
	}
	
	
	
}
void deleteAll(struct NODE **start)
{
	while((*start)!=NULL)
	{
		struct NODE *temp=*start;
		*start=(*start)->next;
		free(temp);
		
	}
	
	
}

int search(struct NODE *start,int vts)
{
	while(start!=NULL )
	{
	if((start)->data==vts)
	{
		return 1;
	}
		start=start->next;
	}
	return 0;
}
void insertionSort(struct NODE **start)
{
		struct NODE *temp,*pnt;
		pnt=*start;
		
		while(pnt->next != NULL)
		{
			temp=pnt->next;
			while(temp!=*start && (temp->data) < (temp->prev->data) )
			{
				
					int t = temp->data;
					temp->data=temp->prev->data;
					temp->prev->data=t;
				
				  temp=temp->prev;
			}
			printList(*start);
			pnt=pnt->next;
		}
}












