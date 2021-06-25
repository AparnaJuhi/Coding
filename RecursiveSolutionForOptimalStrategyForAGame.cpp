long long fun(int arr[] ,int i, int j)
{
    if(i+1==j) //only two elements left
    return max(arr[i],arr[j]);
    
    //now there are two conditions - I can pick ith position or jth positon
    
    //since opponent is also playing smartly so whatever I pick, I will get the minimum from remaining
    //as opponent will try best to increase their score
    
    return max((arr[i]+ min(fun(arr,i+2,j), fun(arr,i+1,j-1))),
    (arr[j]+ min(fun(arr,i+1,j-1), fun(arr,i,j-2))));
}
long long maximumAmount(int arr[], int n) 
{
    int i=0;
    int j=n-1;
    return fun(arr, i, j);
}

