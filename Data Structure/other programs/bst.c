#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};
struct Stack{
	struct Node *subTree;
	struct Stack *next;
};
void push(struct Stack **top,struct Node *tree);
struct Node * pop(struct Stack **top);
void preOrder(struct Node **root);
void Insert(struct Node **root,int data);
int main() {
  struct bstnode *root=NULL;
  Insert(&root,15);
  Insert(&root,10);
  Insert(&root,20);
  Insert(&root,25);
 Insert(&root,8);
 preOrder(root);
 //int f=search(root,25);
 //printf(" \n%d ",f);
 
 

 
 return 0;
  
}
  void Insert(struct Node **root,int data)
  {
  	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
  	temp->data = data;
  	temp->left=NULL;
  	temp->right=NULL;
	  if(*root==NULL){
  		
  		*root=temp;
	  }
	  else 
	  	{
	  		struct Node *current=*root;
	  		while(1)
	  		{
	  			
	  			
	  			if(data < current->data )
	  			{
	  				if(current->left==NULL)
	  				{
	  					current->left=temp;
	  					return;
					}
	  				else current=current->left;
				}
				else //if(data > current->data)
				{
					if(current->right==NULL)
	  				{
	  					current->right=temp;
	  					return;
					}
	  				else current=current->right;
				}
	  			
	  			
			  }
		  }
  }
  void inOrder(struct Node *root)
  {
  	if(root!=NULL)
  	{
  		inOrder(root->left);
  		printf(" %d ",root->data);
  		inOrder(root->right);
	  }
   }
   int search(struct Node *root,int vts)
   {
   	struct Node *current=root;
   	
   	
	
		while(1)
		{
			if(current->data==vts)
   		{
   		return 1;
		}
		else if(vts < current->data)
			{
				if(current->left==NULL)
				return 0;
				else
				current=current->left;
			}
			else {
				if(current->right==NULL)
				return 0;
				else
				current=current->right;
			}
		}
		
		
	}
	void push(struct Stack **top,struct Node *tree)
{
	struct Stack *temp=(struct Stack *)malloc(sizeof(struct Stack));
	temp->next=NULL;
	temp->subTree=tree;
	if(*top==NULL)
	{
		*top=temp;
	}
	else {
	   temp->next=*top;
	   *top=temp;
	}
}
struct Node * pop(struct Stack **top)
{
	struct Node *tree;
	if((*top!=NULL))
	{
		tree=(*top)->subTree;
		struct Stack *curr=*top;
		*top=(*top)->next;
		 free(curr);
		 return tree;
	}
	return NULL;
	
}
void preOrder(struct Node **root)
{
	struct Node *current=*root;
	struct Stack **top=NULL;
	while(current->left!=NULL)
	{
		printf(" %d ",current->data);
		push(top,current->left);
		current=current->left;
	}
	
	
}
 
