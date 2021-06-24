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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* k=head;
        int total=(right-left)+1;
        int count=0;
         ListNode* start=NULL,*temp;
        while(count<(left-1))
        {
            if(start==NULL)
            {
                start=new ListNode(k->val);
                temp=start;
            }
            else
            {
                temp->next=new ListNode(k->val);
                    temp=temp->next;
            }
            k=k->next;
            count++;
        }
        
          ListNode* curr=k;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        count=0;
        int i=0;
         ListNode* rhs=head;
        //Now take the node at RHS
         while(count<(right))
        {
            rhs=rhs->next;
            count++;
        }
      
        count=0;
        while(count<(total) && curr!=NULL)
        {
           next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
           count++;
            
        }
        //prev is new head of this ll
        while(prev!=curr && prev!=NULL)
        {
            if(start==NULL)
            {
                start=new ListNode(prev->val);
                temp=start;
            }
            else
            {
                temp->next=new ListNode(prev->val);
                    temp=temp->next;
            }
            prev=prev->next;
          
        }
        
      if(start==NULL)
          return rhs;
        else
        {
            temp->next=rhs;
        }
        return start;
        
    }
};
