#include<stdio.h>
void quicksort(int a[],int low,int high)
{
	int i,j,pivot,temp;
	if(low<high)
	{
		pivot=low;
		i=low;
		j=high;
		while(i<j)
		{
			while(a[i]<=a[pivot]&&i<high)
			i++;
			while(a[j]>a[pivot])
			j--;
			if(i<j)
			{
		    	temp=a[i];
			    a[i]=a[j];
		    	a[j]=temp;
        	}
		}
	temp=a[pivot];
	a[pivot]=a[j];
	a[j]=temp;
	quicksort(a,low,j-1);
	quicksort(a,j+1,high);
}
}
int main()
{
	int i,n,a[25];
	printf("no.of elemmnts are you going to enter?");
	scanf("%d",&n);
	printf("enter %d elements",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("the sorted elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
