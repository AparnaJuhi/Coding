//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:

    int helpaterp(vector<vector<int>> h)
    {
        queue<pair<int,int>>q;
        int toi[h.size()][h[0].size()];
        for(int i=0;i<h.size();i++)
        {
            for(int j=0;j<h[0].size();j++)
            {
                
                if(h[i][j]==2)
                {
                    pair<int,int>pa;
                    pa.first=i;
                    pa.second=j;
                    q.push(pa);
                   toi[i][j]=0; 
                }
                else
                toi[i][j]=INT_MIN;
            }
        }
        int n=h.size();
        int m=h[0].size();
        int maxi=0;
        while(!q.empty())
        {
             pair<int,int>pa=q.front();q.pop();
            int x=pa.first;
            int y=pa.second;
            if((x+1)>=0 &&  (x+1)<n &&  y>=0 && y<m && h[x+1][y]==1)
            {
                
                h[x+1][y]=2;
                toi[x+1][y]=toi[x][y]+1;
                  pair<int,int>pa;
                    pa.first=x+1;
                    pa.second=y;
                    q.push(pa);
        
            }
            if((x-1)>=0 &&  (x-1)<n &&  y>=0 && y<m && h[x-1][y]==1)
            {
                h[x-1][y]=2;
                toi[x-1][y]=toi[x][y]+1;
                 pair<int,int>pa;
                    pa.first=x-1;
                    pa.second=y;
                    
                q.push(pa);
            }
            if(x>=0 &&  x<n &&  y+1>=0 && y+1<m && h[x][y+1]==1)
            {
                h[x][y+1]=2;
                toi[x][y+1]=toi[x][y]+1;
                 pair<int,int>pa;
                    pa.first=x;
                    pa.second=y+1;
                q.push(pa);
            }
            if(x>=0 &&  x<n &&  y-1>=0 && y-1<m && h[x][y-1]==1)
            {
                h[x][y-1]=2;
                toi[x][y-1]=toi[x][y]+1;
                pair<int,int>pa;
                    pa.first=x;
                    pa.second=y-1;
                q.push(pa);
            }
        }
        
         for(int i=0;i<h.size();i++)
        {
            for(int j=0;j<h[0].size();j++)
            {
                if(h[i][j]==1)
                {
                    return -1;
                }
            }
        }
        
        
        //find maximum toi
        
        
         for(int i=0;i<h.size();i++)
        {
            for(int j=0;j<h[0].size();j++)
            {
                maxi=max(maxi, toi[i][j]);
            }
        }
        return maxi;
    
        
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
