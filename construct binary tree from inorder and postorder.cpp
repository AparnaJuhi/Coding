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
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        
        int flag=0; //when flag=1, means right nodes over
        int n=post.size();
        int postIdx=n-1;
        int inIdx=n-1;
        stack<TreeNode*>st;
        TreeNode* root=new TreeNode(post[n-1]);
        TreeNode* prev=root;
        postIdx--;
        st.push(root);
        while(postIdx>=0)
        {
            if(!st.empty() && st.top()->val==in[inIdx])
            {
                flag=1;
                prev=st.top();
                st.pop();
                inIdx--;
            }
            else
            {
               TreeNode* curr=new TreeNode(post[postIdx]); 
                postIdx--;
               if(flag==0)
               {
                   prev->right=curr;
                   prev=prev->right;
               }
                else
                {
                    prev->left=curr;
                    prev=prev->left;
                    flag=0;
                }
                st.push(curr);
            }
        }
        
        return root;
    }
};
