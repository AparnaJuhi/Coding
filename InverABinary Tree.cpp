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
    void mirror(TreeNode* root)
    {
        //mirror tree
        if(root==NULL)
            return;
        else
        {
            TreeNode* temp;
            mirror(root->left);
             mirror(root->right);
            temp=root->left;
            root->left=root->right;
            root->right=temp;
            
        }
        
    }
    TreeNode* invertTree(TreeNode* root) {
        mirror(root);
        return root;
       
        
    }
};
