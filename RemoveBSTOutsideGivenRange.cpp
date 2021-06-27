class Solution {
    public:
    
    Node* mini(Node* t)
    {
        while(t && t->left)
        {
            t=t->left;
        }
        return t;
    }
    struct Node* remov(struct Node* t, int d)
    {
        if(t==NULL)
        {
           return t;
        }
        else if(t->data < d)
        {
            t->right=remov(t->right, d);
        }
        else if(t->data > d)
        {
            t->left=remov(t->left, d);
        }
        else
        {
            if(t->left==NULL && t->right==NULL)
            {
                return NULL;
            }
            else if(t->left==NULL)
            {
                return t->right;
            }
            else if(t->right==NULL)
            return t->left;
            else
            {
                Node *k=mini(t->right);
                t->data=k->data;
                t->right=remov(t->right, k->data);
            }
        }
    }
    
    Node* removekeys(Node* root, int l, int r) {
       //do inorder traversal
       vector<int>remain;
       Node *curr=root;
       stack<Node*>s;
       
       while(curr!=NULL  || !s.empty())
       {
           while(curr!=NULL)
           {
               s.push(curr);curr=curr->left;
           }
           curr=s.top();
           s.pop();
           if(curr->data < l || curr->data > r)
           {
               
               remain.push_back(curr->data);
           }
           curr=curr->right;
       }
        
    
        for(int i=0;i<remain.size();i++)
        {
            root=remov(root,remain[i]);
        }
        return root;
        
    }
};
