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
    void fun(TreeNode* root, vector<int>&v)
    {
        if(root==NULL)
            return;
        fun(root->left, v);
        v.push_back(root->val);
        fun(root->right,v);
    }
    
    
    TreeNode* bstToGst(TreeNode* root) {
        //by prefix sum
        
        //first store all numbers in a vector
        vector<int>v;
        fun(root,v);
        int prefix[v.size()];
        prefix[0]=v[0];
        for(int i=1;i<v.size();i++)
        {
            prefix[i]=prefix[i-1]+v[i];
        }
        //inorder traversal iterative
        stack<TreeNode *> s;
    TreeNode *curr = root;
        int n=prefix[v.size()-1];
  int i=0;
    while (curr != NULL || s.empty() == false)
    {
        while (curr !=  NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
 
        curr->val=((n-prefix[i])+curr->val);
        i++;
        curr = curr->right;
        
        
    }
        return root;}
};
