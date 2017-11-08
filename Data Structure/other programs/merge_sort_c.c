#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void mergeSort(int *,int);
void merge(int *a, int *left,int *right,int nL,int nR);
int main(int argc, char *argv[]) {
	
	int a[]={5,4,2,1,3};
	mergeSort(a,5);
	int i;
	printf(" \n ");
	for(i=0;i<5;i++)
	{
		printf(" %d ",a[i]);
	}
	return 0;
}
void mergeSort(int *a,int n)
{
	
	
	int *left;
	int *right;
	if(n < 2) return;
	
	
	int mid=n/2;
	left=(int*)malloc(sizeof(int)*mid);
	right=(int*)malloc(sizeof(int)*(n-mid));
	int i;
	for(i=0;i<mid;i++)
	{
		left[i]=a[i];
	}
	for(i=mid;i<n;i++)
	{
		right[i-mid]=a[i];
	}
   
	mergeSort(left,mid);
	mergeSort(right,n-mid);
	merge(a, left,right,mid,n-mid);
	free(left);
	free(right);
	
}
void merge(int *a, int *left,int *right,int nL,int nR)
{
	
	int i=0,j=0,k=0;
	
	while(i<nL && j<nR)
	{
		if(left[i] <= right[j])
		{
			a[k]=left[i];
			i++;
			k++;
		}
		else
		{
			a[k]=right[j];
			j++;
			k++;
		}
	}
	while(i < nL) a[k++] = left[i++];
	while(j < nR) a[k++] = right[j++];
	
	
}
