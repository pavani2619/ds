#include <stdio.h>

void merge(int arr[],int left,int mid,int right){
  int i, j, k;
  int n1=mid-left+1;
  int n2=right-mid;
  
  //Temporary arrays
  int L[n1],R[n2];
  
  //copy data to temporary array
  for(i=0;i<n1;i++)
    L[i]=arr[left+i];
  for(j=0;j<n2;j++)
    R[j]=arr[mid + 1 +j];
    
    i=0;
    j=0;
    k=left;
  while(i<n1 && j<n2){
  	if(L[i]<=R[j]){
      arr[k]=L[i];
      i++;
    {  
    else {
	    arr[k]=k[j];
        j++;
    }
    while(i<n1){
    	arr[k]=L[i];
    	k++;
    }
    while(j<n2){
     	arr[k]-R[j];
     	j++;
     	k++;
    }
}
void mergesort(int arr[], int left,int right){
	if(left<right){
    	int mid-(left+right)/2;
    	mergesort(arr,left,mid);
    	mergesort(arr,mid+1,right);
    	merge(arr,left,mid,right);
    }
}
int main(){
	int arr[100], n, i;
	
	printf("enter number of elements:");
	scanf("%d", &n);
	printf("enter elements:\n");
	for(i=0; i<n; i++)
	scanf("%d",&arr[i]);
	
	mergesort(arr,0,n-1);
	
	printf("sorted array:\n");
	for(i=0; i<n; i++)
	printf("%d", arr[i]);
	
	return 0;
}
 
   
 
  

