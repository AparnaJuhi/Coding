struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        Node *curr=root;
        map<int,vector<int>>mp;
        map<Node*, int>val;
        queue<Node*>q;
        //level order traversal of a tree
        q.push(root);
        vector<int>v;
        v.push_back(root->data);
        mp[0]=v;
        val[root]=0;
        while(!q.empty())
        {
            Node* t=q.front();
            q.pop();
            int value=val[t];
            if(t->left)
            {
                if(mp.find(value-1)==mp.end())
                {
                     vector<int>vv;
                      vv.push_back(t->left->data);
                    mp[value-1]=vv;
                }
                else
                mp[value-1].push_back(t->left->data);
                q.push(t->left);
                val[t->left]=value-1;
            }
            if(t->right)
            {
                 if(mp.find(value+1)==mp.end())
                {
                     vector<int>vv;
                      vv.push_back(t->right->data);
                    mp[value+1]=vv;
                }
                else
                mp[value+1].push_back(t->right->data);
                q.push(t->right);
                val[t->right]=value+1;
            }
            
        }
        
        
        //now summing vlaues
        map<int,vector<int>>::iterator it;
        vector<int>ans;
        int sum=0;
        for(it=mp.begin();it!=mp.end();++it)
        {
            vector<int>s=it->second;
            for(int i=0;i<s.size();i++)
            {
                sum+=s[i];
            }
            ans.push_back(sum);
            sum=0;
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main() 
{
    
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        vector <int> res = obj.verticalSum(root);
        for (int i : res) cout << i << " ";
        cout<<endl;
    }
}  // } Driver Code Ends
