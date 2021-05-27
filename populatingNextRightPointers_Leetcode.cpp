/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        //do level order traversal
        if(root==NULL)
            return root;
        queue<Node*>q;
        q.push(NULL);
        q.push(root);
        Node *prev=root;
        int flag=1;
        while(q.size()>1)
        {
            Node *t=q.front();
            q.pop();
            if(t==NULL)
            {
               prev->next=t; 
               q.push(t);
                flag=0;
                continue;
            }
      
        
        if(t->left)
        {
            q.push(t->left);
             if(flag==0)
            {
                flag=1;
                prev=t->left;
                 
            }
            else
            {
                prev->next=t->left;
                prev=prev->next;
            }
            
        }
        if(t->right)
        {
            q.push(t->right);
            if(flag==0)
            {
                flag=1;
                prev=t->right;
                 
            }
            else
            {
                prev->next=t->right;
                prev=prev->next;
            }
        }
              }
        return root;
       
        
    }
};
