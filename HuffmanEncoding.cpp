#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    struct Node{
	       Node* left;
	       Node* right;
	       char ch;
	       int data;
	       Node(char c, int d)
	       {
	           data=d;
	           ch=c;
	           left=NULL;
	           right=NULL;
	       }
	    };
	   struct comp {
        bool operator()(Node* l,Node* r)
    
        {
            return (l->data > r->data);
        }
        };
        
        
        void fun(vector<string>&ans, string str,struct Node* root)
            {
            
                if (!root)
                    return;
            
                if (root->ch != '$')
                {
                
                    ans.push_back(str);
                    
                }
            
                fun(ans, str + "0",root->left);
                fun(ans , str + "1", root->right);
            }


		vector<string> huffmanCodes(string s,vector<int> f,int N)
		{
		    
		    
		    priority_queue<Node*, vector<Node*>, comp> minHeap;
		    
		     for (int i = 0; i < s.size(); ++i)
             minHeap.push(new Node(s[i], f[i]));
             Node* left;
             Node* right;
             Node* top;
             
		   while (minHeap.size() != 1) 
		   {
                left = minHeap.top();
                minHeap.pop();
        
                right = minHeap.top();
                minHeap.pop();
                top = new Node('$', left->data + right->data);
        
                top->left = left;
                top->right = right;
        
                minHeap.push(top);
            }
            
            vector<string>ans;
            string p="";
            fun(ans,p, minHeap.top());
            return ans;

		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends
