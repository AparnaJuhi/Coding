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
    int maxPathUtil(TreeNode* root, int &ans)
    {
          if(root==NULL)
            return 0;
        int i=root->val;
        int j=maxPathUtil(root->left, ans);
        int k=maxPathUtil(root->right, ans);
        //as if we dont subtract i then root->val will be added two times
        int l=(j+k)+i;
        ans=max(ans,max(max(max(i,j+i),k+i),l));
        int singlePath=max(i, max(j+i,k+i));
        return singlePath;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxPathUtil(root, ans);
        return ans;
      
        
    }
};
