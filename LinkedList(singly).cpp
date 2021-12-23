//LINKED LIST:
// 1.Insertion(Tail+Head).
// 2.Deletion(Itr+Rec).
// 3.Reverse(Itr+Rec).
// 4.Reverse k nodes.
// 5.Cycle:- i-> generate
//           ii-> detect
//           iii-> remove
// 6.Append last k-nodes to start.


#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
	    node(int val)
	    {
	    	data=val;
		}
};
void displayList(node* first)
{
	while(first!=0)
	{
	
		cout<<first->data<<"->";
	    first=first->next;
	}
	cout<<endl;
}
void displayRec(node* first,int n)
{
	if(first==0)
	{
		return;
	}
	else
	{
		if(n==1)
		{
			cout<<first->data;
			displayRec(first->next,n-1);
		}
		else
		{
			cout<<first->data<<"->";
			displayRec(first->next,n-1);
		}
	}
	cout<<endl;
}
void InsertAtTail(node* &head,int val)
{
	node* n=new node(val);
	if(head==0)         //If no node exists in the list
	{
		head=n;
		head->next=0;    //NOTE
		return;
	}
	node* temp=head;        //temp initially points to the first node
	while(temp->next!=0)
	{
		temp=temp->next;
	}
	temp->next=n;
	n->next=0;    //NOTE
}
void createListOfnNodes()
{
	int n;
	printf("Enter the no of nodes\n");
	cin>>n;
	node* head;
	node* last;
	for(int i=1;i<=n;i++)
	{
		int data;
		cin>>data;
		if(i==1)
		{
			node* nod=new node(data);
			head=nod;
			nod->next=NULL;
			last=nod;
		}
		else
		{
			node* nod=new node(data);
			last->next=nod;
			last=nod;
			nod->next=NULL;
		}
		//last=nod thus we can still add more nodes if we wish to..
	}
}
void InsertAtHead(node* &head,int val)
{
	node* n=new node(val);
	n->next=head;
	head=n;
}
void DeleteNode(node* &head,int val)
{
	if(head->data==val)
	{
		node* temp=head->next;
		head->next=0;
		head=temp;
	}
	else
	{
		node* temp=head;
		while(temp->next!=0)
		{
			if((temp->next)->data==val)
		   {
			    node *tempp=temp->next;
			    temp->next=tempp->next;
		   }
		   else
		   {
		     	temp=temp->next;
		   }  
	    }
	}
}
node* reverseIterative(node* head)     //Note here the head pointer should also point to the last node
{
	node* curr=head;
	node* prev=0;
	node* next;
	while(curr->next!=0)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	curr->next=prev;
	return curr;
}
node* reverseRecursive(node* &head,node* last)
{
	if(head->next==0)                   //Base condition
	{
		head->next=last;
		node* newHead=head;
		return newHead;
		//cout<<head->data<<"->";
	}
		
	else
	{
		node* newHead=reverseRecursive(head->next,head);
		head->next=last;  
		return newHead;   
		//cout<<head->data<<"->";   
	}
}

node* reverseK(node* head,int k)     //Revesing the subsection of k nodes and recursively applying it again
{
	node* prevptr=0;
	node* currptr=head;
	node* nextptr;
	int cnt=0;
	while(currptr!=0&&(cnt<k))
	{
		nextptr=currptr->next;
		currptr->next=prevptr;
		prevptr=currptr;
		currptr=nextptr;
		cnt++;
	}
	if(nextptr!=0)
	{
		head->next=reverseK(nextptr,k);
	}
	return prevptr;
}

void createCycle(node* head,int pos)
{
	int cnt=1;
	node* temp=head;
	node* cyclepos;
	while(temp->next!=0)
	{
		if(cnt!=pos)
		{
			temp=temp->next;
			cnt++;
		}
		else
		{
			cyclepos=temp;
			temp=temp->next;
			cnt=-1;
		}
	}
	temp->next=cyclepos;
}

bool detectCycle(node* head)
{
	node* slow=head;
	node* fast=head;
	while(fast!=0&&fast->next!=0)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			return true;
		}
	}
	return false;
}

void removeCycle(node* head)
{
	node* slow=head;
	node* fast=head;
	do
	{
		slow=slow->next;
		fast=fast->next->next;
	}while(slow!=fast);
	fast=head;
	while(slow->next!=fast->next)
	{
		slow=slow->next;
		fast=fast->next;
	}
	slow->next=0;
}

node* lastKtoStart(node* head,int pos)
{
	int n=0;
	int cnt=1;
	node* temp=head;
	while(temp->next!=0)
	{
		n++;
		temp=temp->next;
	}
	n++;     //Total number of nodes in the list
	int go=n-pos;
	node* tempp=head;
	while(cnt!=go)
	{
		tempp=tempp->next;
		cnt++;
	}
	node* newHead=tempp->next;
	tempp->next=0;
	temp->next=head;
	return newHead;
}
int main()
{
	   node* head=NULL;
	   InsertAtTail(head,1);
	   InsertAtTail(head,2);
	   InsertAtTail(head,3);
	   InsertAtTail(head,4);
	   InsertAtTail(head,5);
	   InsertAtTail(head,6);
	   InsertAtTail(head,7);
	   displayList(head);
	   //node* newHead=lastKtoStart(head,1);
	   //displayList(newHead);
	   //node* newHead=reverseK(head,3);
	   //InsertAtHead(head,0);
	   //node* newHeadRec=reverseRecursive(head,NULL);
	   //node* newHeadItr=reverseIterative(head);
	   //displayList(newHeadRec);
	   //displayList(newHeadItr);
	   //DeleteNode(head,1);
	   //createCycle(head,2);
	   //int ans=detectCycle(head);cout<<ans<<endl;
	   //removeCycle(head);
	   //displayList(head);
       //displayRec(head,n);
}
  




