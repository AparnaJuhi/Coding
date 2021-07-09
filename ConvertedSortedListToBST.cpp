/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* BST(vector<int>v, int l, int r)
    {
        if(l>r)
            return NULL;
        int mid=(l+r)/2;
        TreeNode* node=new TreeNode(v[mid]);
        node->left=BST(v,l,mid-1);
        node->right=BST(v,mid+1,r);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
            
        vector<int>v;
        while(head!=NULL)
        {
            v.push_back(head->val);head=head->next;
        }
        return BST(v,0,v.size()-1);
        
    }
};
