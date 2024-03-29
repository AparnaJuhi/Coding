#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int select(int arr[], int i);
void selectionSort(int arr[], int n);
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}// } Driver Code Ends


void selectionSort(int arr[], int n)
{
  //find minimum elment and swap from beginning
  for(int i=0;i<n-1;i++)
  {
      int mini=arr[i];
      int minIdx=i;
      for(int j=i+1;j<n;j++)
      {
          if(arr[j]<mini)
          {
              mini=arr[j];
              minIdx=j;
          }
      }
      int k=arr[minIdx];
      arr[minIdx]=arr[i];
      arr[i]=k;
  }
  
}
