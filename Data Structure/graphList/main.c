#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 struct Vertex
 {
 	int data;
 	struct Edge *edgeList;
 	struct Vertex *nextVertex;
 	int isVisited;
 };
 struct Edge
 {
 	int data;
 	struct Edge *nextEdge;
 };
 struct Node{
 	struct Vertex *vertex;
 	struct Node *next;
 }*top=NULL;
 struct NodeStack{
	struct Vertex *vertex;
	struct stack *next;

}*topStack=NULL;
struct Vertex *peek();
struct Vertex *pop();
void addVertex(struct Vertex **start,int value);
void addEdge(struct Vertex **start,int v1,int v2);
struct Vertex *returnVertexAddress(struct Vertex **start,int value);
struct Vertex *DeQueue();
int main(int argc, char *argv[]) {

	struct Vertex *start=NULL;
  addVertex(&start,0);
   addVertex(&start,1);
addVertex(&start,2);
addVertex(&start,3);
addVertex(&start,4);
addVertex(&start,5);
addVertex(&start,6);

addEdge(&start,0,1);
addEdge(&start,0,4);
addEdge(&start,0,2);
addEdge(&start,1,2);
addEdge(&start,1,4);
addEdge(&start,2,3);
addEdge(&start,3,6);
addEdge(&start,4,5);

print(start);
BFS(&start);

	return 0;
}

struct Vertex *DeQueue()
{

	struct Vertex *value=NULL;
	if (top==NULL)
	{
		return NULL;
	}
	else
	{

	struct Node *temp=top;
		top=top->next;
		value= (temp->vertex);
		free(temp);
	}
	return value;
}
void EnQueue(struct Vertex *vertex)
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->vertex=vertex;
	temp->next=NULL;
	if(top==NULL)
	{
		top=temp;
	}
	else
	{
		struct Node  *current=top;
	while(current->next!=NULL)
	{
		current=current->next;
	}
	current->next=temp;
	}
}


int isConnected(struct Vertex **start,int v1)
{


            struct Vertex *v=*start;
            while (v!=NULL)
            {
                v->isVisited = 0;
                v = v->nextVertex;
            }
            struct Vertex *s = *start;

            EnQueue(s);


            while (top!=NULL)
            {
                s = DeQueue();
                s->isVisited=1;

               struct Edge *edge = s->edgeList;
                while (edge!=NULL)
                {
                    if (edge->data == v1)
                    {
                    	top=NULL;
                        return 1;
                    }
                        struct Vertex *tempV=returnVertexAddress(start,edge->data);
                    if(tempV->isVisited==0)
            		{
                        EnQueue(tempV);
                    }
                    edge = edge->nextEdge;
                }

            }
            top=NULL;
            return 0;


}
void BFS(struct Vertex **start)
{


            struct Vertex *v=*start;
            while (v!=NULL)
            {
                v->isVisited = 0;
                v = v->nextVertex;
            }
            struct Vertex *s = *start;

            EnQueue(s);
printf("\n");

            while (top!=NULL)
            {
                s = DeQueue();
                if(s->isVisited==0)
                    printf("%d ",s->data);
                s->isVisited=1;

               struct Edge *edge = s->edgeList;
                while (edge!=NULL)
                {

                        struct Vertex *tempV=returnVertexAddress(start,edge->data);
                    if(tempV->isVisited==0)
            		{
                        EnQueue(tempV);
                    }
                    edge = edge->nextEdge;
                }

            }
            top=NULL;
            return 0 ;


}
int DFS(struct Vertex **start,int v1)
{


            struct Vertex *v=*start;
            while (v!=NULL)
            {
                v->isVisited = 0;
                v = v->nextVertex;
            }
            struct Vertex *s = *start;

            push(s);


            while (topStack!=NULL)
            {
                s = peek();

				s->isVisited=1;

               struct Edge *edge = s->edgeList;
                while (edge!=NULL)
                {

                    if (edge->data == v1)
                    {
                    	topStack=NULL;

                        return 1;
                    }
                        struct Vertex *tempV=returnVertexAddress(start,edge->data);
                    if(tempV->isVisited==0)
            		{
                        push(tempV);
                        break;
                    }
                    edge = edge->nextEdge;
                    if(edge->nextEdge==NULL)pop();
                }

            }
            topStack=NULL;
            return 0;


}
void path(struct Vertex **start,int v1)
{

           if(isConnected(start,v1)==1)
           {

            struct Vertex *v=*start;
            while (v!=NULL)
            {
                v->isVisited = 0;
                v = v->nextVertex;
            }
            struct Vertex *s = *start;

            EnQueue(s);

printf("\n");
            while (top!=NULL)
            {
                s = DeQueue();
                if(s->isVisited==0)printf("%d->",s->data);

                s->isVisited=1;

               struct Edge *edge = s->edgeList;
                while (edge!=NULL)
                {
                    if (edge->data == v1)
                    {
                    	top=NULL;
                    	printf("%d",edge->data);
                        return 1;
                    }
                        struct Vertex *tempV=returnVertexAddress(start,edge->data);
                    if(tempV->isVisited==0)
            		{
                        EnQueue(tempV);
                    }
                    edge = edge->nextEdge;
                }

            }
            top=NULL;
            return 0;
}
else
{
	printf("Path not exists");
}

}

void addVertex(struct Vertex **start,int value)
{
	struct Vertex *temp=(struct Vertex *)malloc(sizeof(struct Vertex));
	temp->data=value;
	temp->edgeList=NULL;
	temp->nextVertex=NULL;


	if((*start)==NULL)
	{
		*start=temp;
	}
	else
	{
		struct Vertex *current=*start;
		while(current->nextVertex!=NULL)
		{
			current=current->nextVertex;
		}
		current->nextVertex=temp;
	}

}

void addEdge(struct Vertex **start,int v1,int v2)
{
	struct Edge *temp=(struct Edge *)malloc(sizeof(struct Edge));
	temp->data=v2;
	temp->nextEdge=NULL;

		struct Vertex *vertex=returnVertexAddress(start,v1);

	if( vertex->edgeList ==NULL)
	{
	vertex->edgeList=temp;
	}
	else
	{

		struct Edge *current=vertex->edgeList;
		while(current->nextEdge !=NULL)
		{

			current=current->nextEdge;
		}
		current->nextEdge=temp;
	}


	struct Vertex *vertex2=returnVertexAddress(start,v2);

	struct Edge *temp2=(struct Edge *)malloc(sizeof(struct Edge));
	temp2->data=v1;
	temp2->nextEdge=NULL;


	if( vertex2->edgeList ==NULL)
	{

	vertex2->edgeList=temp2;
	}
	else
	{
		struct Edge *current=vertex2->edgeList;
		while(current->nextEdge !=NULL)
		{
			current=current->nextEdge;
		}
		current->nextEdge=temp2;
	}

}
  int isAdjacent(struct Vertex **start,int v1,int v2)
        {
            struct Vertex *vertex1 = returnVertexAddress(start,v1);
            	struct Edge *current=vertex1->edgeList;
		while(current!=NULL)
		{
			if(current->data==v2)return 1;
			current=current->nextEdge;
		}
	return 0;
}
int degree(struct Vertex **start,int v)
{
	int count=0;

	struct Vertex *vertex1 = returnVertexAddress(start,v);

		struct Edge *current=vertex1->edgeList;

		while(current!=NULL)
		{
			count++;
			current=current->nextEdge;
		}
		return count;
}
void print(struct Vertex *start)
{
	struct Vertex *currV=start;
	while(currV!=NULL)
	{
		printf(" \n %d | ",currV->data);
		struct Edge *edge=currV->edgeList;
		while(edge!=NULL)
		{
			printf(" %d ",edge->data);
			edge=edge->nextEdge;
		}
		currV=currV->nextVertex;
	}
}
struct Vertex *returnVertexAddress(struct Vertex **start,int value)
{
	struct Vertex *curr=*start;
	while(curr!=NULL)
	{
		if(curr->data == value)
		return curr;

		curr=curr->nextVertex;
	}
	return NULL;
}
void push(struct Vertex *vertex)
{
	struct NodeStack *temp=(struct NodeStack*)malloc(sizeof(struct NodeStack));
	temp->vertex=vertex;
	temp->next=NULL;
	if(topStack==NULL)
	{
		topStack=temp;
	}
	else
	{
		temp->next=topStack;
		topStack=temp;
	}
}

struct Vertex *pop()
{
	struct Vertex *value=NULL;

	if (topStack==NULL)
	{
		return NULL;
	}
	else
	{

		struct NodeStack *temp=topStack;
		topStack=topStack->next;
		value=temp->vertex;
		free(temp);

	}
	return value;
}
struct Vertex *peek()
{
	struct Vertex *value=NULL;

	if (topStack==NULL)
	{
		return NULL;
	}
	else
	{

		struct NodeStack *temp=topStack;
		//topStack=topStack->next;
		value=temp->vertex;
		//free(temp);

	}
	return value;
}
