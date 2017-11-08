#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {


	int n;
	printf("Enter number of vertices : ");
	scanf("%d",&n);
	int matrix[n][n];
	int vertices[n];
	int isVisited[n][n];
		int i,j;
	for(i=0;i<n;i++)
	{

		for(j=0;j<n;j++)
		{
			isVisited[i][j]=0;
		}

	}

	for(i=0;i<n;i++)
	{
		printf("Enter vertex %d : ",i+1);
	  scanf("%d",&vertices[i]);
	}
	setMatrix(n,matrix);


	addEdge(1,3,n,matrix,vertices,2);
	addEdge(1,4,n,matrix,vertices,5);
	addEdge(2,3,n,matrix,vertices,1);
	addEdge(3,4,n,matrix,vertices,3);

	printMatrix(n,matrix,vertices);

	prims(n,vertices,matrix,isVisited);
	return 0;

}
void prims(int n,int vertices[],int matrix[][n],int isVisited[][n])
{
int i;
for(i=0;i<n-1;i++)
{
	int min=findMin(i,n,matrix,isVisited);
	int minRI=findMinRow(i,n,matrix,isVisited);
	int minCI=findMinCol(i,n,matrix,isVisited);

	printf("\n {%d,%d} = %d ",key(vertices,minRI),key(vertices,minCI),matrix[minRI][minCI]);

	isVisited[minRI][minCI]=1;
	isVisited[minCI][minRI]=1;
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
void addEdge(int v1,int v2,int n,int matrix[][n],int vertices[],int weight)
{

			 int i1 = index(vertices,n,v1);
            int i2 = index(vertices,n,v2);
            matrix[i1][i2] = weight;
            matrix[i2][i1] = weight;
}
int findMin(int tillRow,int n,int matrix[][n],int isVisited[][n])
        {
            int min =999;
            int i,j;
            for (i = 0; i <= tillRow ; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (matrix[i][j] < min && matrix[i][j] != 0 && isVisited[i][j] == 0)
                        min = matrix[i][j];
                }
            }
            return min;
        }
        int findMinRow(int tillRow,int n,int matrix[][n],int isVisited[][n])
        {
            int min =999;
            int i,j,row=0;
            for (i = 0; i <= tillRow ; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (matrix[i][j] < min && matrix[i][j] != 0 && isVisited[i][j] == 0)
                        {

						min = matrix[i][j];
						row=i;
					}
                }
            }
            return row;
        }
          int findMinCol(int tillRow,int n,int matrix[][n],int isVisited[][n])
        {
            int min =999;
            int i,j,col=0;
            for (i = 0; i <= tillRow ; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (matrix[i][j] < min && matrix[i][j] != 0 && isVisited[i][j] == 0)
                        {

						min = matrix[i][j];
						col=j;
					}
                }
            }
            return col;
        }
