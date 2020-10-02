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

Node* pairWiseSwap(Node* head);

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i<n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		head = pairWiseSwap(head);
		printList(head);
	}
	return 0; 
}
// } Driver Code Ends


/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/

Node* pairWiseSwap(struct Node* head) {
    if(head==NULL)
    return head;
    vector<int>v;
    Node *s=head;
    Node *k=head;
    while(k!=NULL)
    {
        v.push_back(k->data);
        k=k->next;
    }
    if(v.size()==1)
    return head;
    else
    {
        for(int i=1;i<v.size();i++)
        {
            if(i%2!=0)
            {
                swap(v[i],v[i-1]);
            }
        }
    }
    Node *ss=s;
    for(int i=0;i<v.size();i++)
    {
        s->data=v[i];
        s=s->next;
    }
    return ss;
}

