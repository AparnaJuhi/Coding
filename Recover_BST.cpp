/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        //do inorder traversal to get all the nodes
        stack<TreeNode*>s;
        set<int>v;
        TreeNode* curr=root;
        while(curr!=NULL || !s.empty())
        {
            while(curr!=NULL)
            { s.push(curr);curr=curr->left;
            }
            curr=s.top();
            s.pop();
            v.insert(curr->val);
            
            curr=curr->right;
        }
        
        curr=root;
        set<int>:: iterator it;
        it=v.begin();
        while(curr!=NULL || !s.empty())
        {
            while(curr!=NULL)
            {  
                s.push(curr);
            curr=curr->left;
            }
            curr=s.top();s.pop();
            curr->val=*it;
            it++;
            curr=curr->right;
        }
        
    }
};
