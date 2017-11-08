#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int pop(int stack[],int *top);
int index(int vertices[],int n,int key);
int key(int vertices[] ,int index);
int main(int argc, char *argv[]) {


	int n;
	printf("Enter number of vertices : ");
	scanf("%d",&n);
	int matrix[n][n];
	int vertices[n];



	int i,j;
	for(i=0;i<n;i++)
	{
		printf("Enter vertex %d : ",i+1);
	  scanf("%d",&vertices[i]);
	}
	for(i=0;i<n;i++)
	{

		for(j=0;j<n;j++)
		{
			matrix[i][j]=0;
		}

	}


	addEdge(0,1,n,matrix,vertices);
	addEdge(0,2,n,matrix,vertices);
	addEdge(0,4,n,matrix,vertices);
	addEdge(1,2,n,matrix,vertices);
	addEdge(1,4,n,matrix,vertices);
	addEdge(4,5,n,matrix,vertices);
	addEdge(2,3,n,matrix,vertices);
	addEdge(3,6,n,matrix,vertices);
BFS(0,n,matrix,vertices);
	//printMatrix(n,matrix,vertices);
	return 0;

}
void BFS(int v,int n,int matrix[][n],int vertices)
{
int isVisited[n];
    int i;


    int front=0;
    int rear=0;
    int queue[n];
    for( i = 0 ; i < n  ; i++ )
    {
        isVisited[i]=0;
        queue[i]=0;
    }
        int s = index(vertices,n,v);
     //isVisited[s]=1;
        printf("\n");
        queue[rear]=s;
        rear++;

        while(rear != front)
        {
           s=queue[front];//Dequeue
           front++;//
            if(isVisited[s]==0)
           printf(" %d ",s);
isVisited[s] = 1;//mark as visited
            for(i=0;i<n;i++)
            {
                if (matrix[s][i]== 1 && isVisited[i]==0)
                {
                    queue[rear] = i;//Enqueue
                    rear++; //


                }
            }
        }


}
void DFS(int v,int n,int matrix[][n],int vertices)
{
    int isVisited[n];
    int i;


    int top=-1;
    int stack[n];
    for( i = 0 ; i < n  ; i++ )
    {
        isVisited[i]=0;
        stack[i]=0;
    }
        int s = index(vertices,n,v);
     //isVisited[s]=1;
        printf("\n");
        push(stack,&top,s);


            while (top != -1)
            {
                s = peek(stack,&top);
                if(isVisited[s]==0)
                    printf(" %d ",key(vertices,s));

                isVisited[s]=1;

				for(i=0;i<n;i++)
                {
                     if(matrix[s][i]==1 && isVisited[i]==0)
                    {
                        push(stack,&top,i);
                        break;
                    }
                    if(i == n-1)pop(stack,&top);
                }
            }


}
void printMatrix(int n,int matrix[][n],int vertices[])
{
		int i,j;
	for(i=0;i<n;i++)
	{
		printf("\n %d |  ",key(vertices,i));
		for(j=0;j<n;j++)
		{
			printf("%d \t",matrix[i][j]);
		}

	}
}

int index(int vertices[],int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(vertices[i] == key)
		{
			return i;
		}
	}
}
int key(int vertices[] ,int index)
{
	return vertices[index];
}
void addEdge(int v1,int v2,int n,int matrix[][n],int vertices[])
{
			 int i1 = index(vertices,n,v1);
            int i2 = index(vertices,n,v2);
            matrix[i1][i2] = 1;
            matrix[i2][i1] = 1;
}
void push(int stack[],int *top,int value)
{
    ++(*top);
    stack[*top]=value;
}
int pop(int stack[],int *top)
{
    if(*top == -1)
    {
        return -1; // means stack is empty
    }
    int temp=stack[*top];
    --(*top);
    return temp;
}
int peek(int stack[],int *top)
{
    if(*top == -1)
    {
        return -1; // means stack is empty
    }
    int temp=stack[*top];
    return temp;
}
//void EnQueue(int queue[],int *front,int *rear,int value)
//{
//    ++(*rear);
//    queue[*rear]=value;
//}
//int DeQueue(int queue[],int *front,int *rear)
//{
//    int temp=queue[*front];
//    ++(*front);
//    return temp;
//}
//int qFront()
