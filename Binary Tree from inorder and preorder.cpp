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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=1;
        int inIndex=0;
        
        //Making a root node
        TreeNode* root=new TreeNode(preorder[0]);
        
        //flag is used to know whether we need to go left or right
        int flag=0;
        
        TreeNode* prev=root;
        
        //prev is used to assign values to node
        
        stack<TreeNode*>st;
        st.push(root);
        
        while(preIndex < preorder.size())
        {
            if(!st.empty() && st.top()->val==inorder[inIndex])
            {
               
                inIndex++;
                prev=st.top();
                st.pop();
                
               
                //because left elements are over now
                // we have reached the parent
                flag=1;
               
            }
            else
            {
                if(flag==0)
                {
                    prev->left=new TreeNode(preorder[preIndex]);
                    prev=prev->left;
                    
                }
                else
                {
                    flag=0;
                    prev->right=new TreeNode(preorder[preIndex]);
                    prev=prev->right;
                }
                st.push(prev);
                preIndex++;
            }
        }
        return root;
         
    }
};
