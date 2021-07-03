#include<bits/stdc++.h>
using namespace std;


void printPostOrder(int in[], int pre[], int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int pre[N],in[N];
        for(int i=0;i<N;i++)
            cin>>in[i];
        for(int i=0;i<N;i++)
            cin>>pre[i];
        printPostOrder(in,pre,N);
        cout<<endl;

    }
}
// } Driver Code Ends


/*prints the post order traversal of the 
tree */

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void postOrder(Node* root)
{if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void printPostOrder(int in[], int pre[], int n)
{

        int i=0;
        int p=1;
        stack<Node*>s;
        Node *root=new Node(pre[0]);
        s.push(root);
        int flag=0;
        Node* prev=root;
        while(p<n)
        {
            if(!s.empty() && s.top()->data==in[i])
            {
                flag=1; //move right
                i++;
                prev=s.top();
                s.pop();
            }
            else
            {
                if(flag==0)
                {
                    Node *temp=new Node(pre[p]);
                    prev->left=temp;
                    prev=prev->left;
                    
                }
                else
                {
                    Node *temp=new Node(pre[p]);
                    prev->right=temp;
                    prev=prev->right;
                    flag=0;
                }
                s.push(prev);
                p++;
            }
            
        }
postOrder(root);
}
