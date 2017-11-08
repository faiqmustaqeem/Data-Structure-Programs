#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int uni(int i,int j,int parent[]);
int main(int argc, char *argv[]) {


	int n;
	printf("Enter number of vertices : ");
	scanf("%d",&n);
    int vertices[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("\nEnter %d vertex : ",i+1);
        scanf("%d",&vertices[i]);
    }
	int matrix[n][n];



	for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    {
        matrix[i][j]=0;

    }
    }
    setMatrix(n,matrix);
   addEdge(4,1,3,n,matrix,vertices);
	addEdge(4,2,6,n,matrix,vertices);
	addEdge(4,5,6,n,matrix,vertices);
 addEdge(1,2,5,n,matrix,vertices);
addEdge(1,0,3,n,matrix,vertices);
addEdge(0,2,1,n,matrix,vertices);
addEdge(0,3,6,n,matrix,vertices);
addEdge(2,3,5,n,matrix,vertices);
addEdge(2,5,4,n,matrix,vertices);
addEdge(3,5,2,n,matrix,vertices);
	printMatrix(n,matrix,vertices);
krushkals(n,matrix,vertices);
	return 0;

}
void krushkals(int n,int matrix[][n],int vertices[])
{
      int i,j,mincost,min,minR,minC,rTemp,cTemp,count =0;
    int isVisited[n][n];
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    {
        isVisited[i][j]=0;
    }
    }

    int parent[n];
    for(i=0;i<n;i++)
    {
        parent[i]=i;
    }
    printf("\n");
    while(count < n-1)
    {
         min =999;
            for (i = 0; i < n ; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (matrix[i][j] < min && matrix[i][j] != 0 && isVisited[i][j] == 0)
                     {
                         min = matrix[i][j];
                         minR=i;
                         minC=j;
                     }
                }
            }
            rTemp=minR;
            cTemp=minC;
            minR=root(minR,parent);
            minC=root(minC,parent);
        if(uni(minR,minC,parent) == 1)
		{
			printf(" (%d,%d) =%d\n",key(vertices,rTemp),key(vertices,cTemp),min);
			mincost +=min;
		}
        isVisited[cTemp][rTemp]=1;
        isVisited[rTemp][cTemp]=1;
        ++count;

    }
    printf("\n  minimum cost is %d ",mincost);



}
void printMatrix(int n,int matrix[][n],int vertices[])
{
		int i,j;
	for(i=0;i<n;i++)
	{
		printf("\n %d |  ",vertices[i]);
		for(j=0;j<n;j++)
		{
			printf("%d \t",matrix[i][j]);
		}

	}
}
void setMatrix(int n,int matrix[][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)matrix[i][j]=0;
			else matrix[i][j]=99; //99 means infinity
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
void addEdge(int v1,int v2,int weight,int n,int matrix[][n],int vertices[])
{

			 int i1 = index(vertices,n,v1);
            int i2 = index(vertices,n,v2);
            matrix[i1][i2] = weight;
            matrix[i2][i1] = weight;
}
int root(int i,int parent[])
{
	while(parent[i] != i)
	i=parent[i];
	return i;
}
int uni(int i,int j,int parent[])
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

