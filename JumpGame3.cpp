class Solution {
public:
    /*
    bool fun(int count, int start, vector<int>arr, bool visited[], int n, bool dp[])
    {
        if(arr[start]==0)
            return true;
        if(count==n)
            return false;
        if(dp[start]==false)
            return false;
        if(start - arr[start] >=0 && dp[start-arr[start]])
        {
            if(visited[start-arr[start]]==false)
            {count++;
            visited[start-arr[start]]=true;
            if(fun(count,start-arr[start], arr, visited, n, dp)==true)
                return true;
             else{
             dp[start-arr[start]]=false;
             count-=1;
             visited[start-arr[start]]=false;}
            }
             
        }
        if(start + arr[start] < n  && dp[start+arr[start]])
        {
            if(visited[start+arr[start]]==false)
            {count++;
            visited[start+arr[start]]=true;
            if(fun(count,start+arr[start], arr, visited, n, dp)==true)
                return true;
             else{
             dp[start+arr[start]]=false;
             count-=1;
             visited[start+arr[start]]=false;}}
             
        }
        
        return false;
    }*/
    /*
    
     bool fun(int start, vector<int>arr, bool visited[] , int n)
     {
          if(start>=0 && start<n )
          {if(arr[start]==0)
             return true;}
         if(start>=0 && start<n && visited[start]==false)
         {visited[start]=true;
         return(fun(start+arr[start],arr,visited, n) || fun(start-arr[start],arr,visited,n));
         }
         return false;
        
     }
    bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size();
        
        bool visited[n];
        memset(visited, false, n);
        int count=1; //count of visited
        
        
        return (fun(start, arr, visited,n));
        
    }*/
    
    
    
     bool fun(int start, vector<int>&arr, int n)
     {
          if(start>=0 && start<n )
          {if(arr[start]==0)
             return true;}
         if(start>=0 && start<n && arr[start]!=-1)
         {
          int k=start+arr[start];
         int intial=arr[start];
          arr[start]=-1;
          bool a=fun(k,arr, n) ;
          arr[start]=intial;
          k=start-arr[start];
             intial=arr[start];
          arr[start]=-1;
          bool v=fun(k,arr,n);
          arr[start]=intial;
          return  a||v;
         }
         return false;
        
     }
    bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size();
        
        
        return (fun(start, arr,n ));}
};
