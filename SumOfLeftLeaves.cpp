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
    int sumOfLeftLeaves(TreeNode* root) {
        
        //do level order traversal
        int sum=0;
        queue<TreeNode*>q;q.push(root);
        while(!q.empty())
        {
            TreeNode* p= q.front();
            q.pop();
            if(p->left)
            {
                q.push(p->left);
                if(p->left->left==NULL && p->left->right==NULL)
                {
                    sum+=p->left->val;
                }
            }
            if(p->right)
            {
                q.push(p->right);
            }
            
        }
        return sum;
        
    }
};
