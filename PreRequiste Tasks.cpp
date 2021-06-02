#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& p) {
	    // Code here
	    
	    vector<int>adj[N];
	    for(int i=0;i<p.size();i++)
	    {
	        pair<int, int>t=p[i];
	        adj[p[i].first].push_back(p[i].second);
	    }
	    
	    
	    ///by bfs
	    
	    //count indegrees of vertices
	    
	    int indegree[N];
	    for(int i=0;i<N;i++)
	    indegree[i]=0;
	    
	    for(int i=0;i<N;i++)
	    {
	        for(int j:adj[i])
	        {
	            indegree[j]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<N;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }

	    int count=0;
	    while(!q.empty())
	    {
	        int f=q.front();
	        q.pop();
	        count++;
	        for(int u:adj[f])
	        {
	            indegree[u]--;
	            if(indegree[u]==0)
	            q.push(u);
	        }
	        
	    }
	   
	    if(count==N)
	    return true;
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
