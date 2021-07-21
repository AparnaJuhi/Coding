// C program for insertion sort
#include <stdio.h>
#include <math.h>

void insertionSort(int arr[], int n);



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

    insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends

 
    void insertionSort(int arr[], int n)
    {
        for(int i=1;i<n;i++)
        {
            int current=arr[i];
            int j=i-1;
            while(arr[j]>current && j>=0)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=current;
        }
        
    }





