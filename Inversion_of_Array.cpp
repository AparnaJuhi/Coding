#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
     long long int merge(long long arr[],long long temp[],long long mid,long long left,long long  right)
    {
        long long i=left;
        long long k=left;
        long long j=mid;
        long long count=0;
        while((i<=mid-1) && (j<=right))
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            else
            {
                temp[k++]=arr[j++];
                count+=(mid-i);
            }
        }
        while(i<=mid-1)
        temp[k++]=arr[i++];
        while (j<=right)
         temp[k++]=arr[j++];
         for(long long ii=left;ii<=right;ii++)
        {
            arr[ii]=temp[ii];
        }
        return count;
        
    }
    
    
    
    long long int mergeSort(long long arr[],long long temp[],long long left,long long  right)
    {
        long long mid=(left+right)/2;
        long long int count=0;
        if(right>left)
        {
            count+=mergeSort(arr,temp,left,mid);
            count+=mergeSort(arr,temp,mid+1,right);
            count+=merge(arr,temp,mid+1,left,right);
        }
        return count;
    }
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        // make a copy of arr as temp
        for(long long i=0;i<N;i++)
        {
            temp[i]=arr[i];
        }
        return mergeSort(arr,temp,0,N-1);
    }

};


int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
