//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:

    Node* addOne(Node *head) 
    {
       vector<int>v1;
       Node *first1=head;
        while(first1)
        {
            v1.push_back(first1->data);
            first1=first1->next;
        }
         reverse(v1.begin(),v1.end());
         vector<int>ans;
         int k,carry;
          k=(v1[0]+1)%10;
          ans.push_back(k);
         int i=1;
         carry=(v1[0]+1)/10;
         while(i<v1.size())
            {
               k=(v1[i]+carry)%10;
              ans.push_back(k);
            
             carry=(v1[i]+carry)/10;
            i++;
             
            }
    if(carry==1)
    {
        ans.push_back(1);
    }
    reverse(ans.begin(),ans.end());
    struct Node *start=NULL,*temp=NULL;
    for(int i=0;i<ans.size();i++)
    {
        if(start==NULL)
        {
            start=new Node(ans[i]);
            temp=start;
        }
        else
        {
            temp->next=new Node(ans[i]);
            temp=temp->next;
        }
    }
    
    return start;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends
