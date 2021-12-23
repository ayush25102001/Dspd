//DOUBLY LINKED LIST:
// 1. Insertion(head+tail).
// 2. Deletion.




#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node* prev;
		node* next;
		node(int val)
		{
			data=val;
		}
};

void insertAtHead(node* &head,int val)
{
	node* n=new node(val);
	if(head==0)
	{
		head=n;
		head->prev=0;
		head->next=0;
		return;
	}
	head->prev=n;
	n->next=head;
	head=n;
}

void insertAtTail(node* &head,int val)
{
	node* n=new node(val);
	if(head==0)
	{
		insertAtHead(head,val);
		return;
	}
	node* temp=head;
	while(temp->next!=0)
	{
	     temp=temp->next;	
	}
	temp->next=n;
	n->prev=temp;
	n->next=0;
}

void deleteNode(node* &head,int pos)
{
	if(pos==1)
	{
		node* temp=head;
		temp->next->prev=0;
		head=temp->next;    //head would be changed
		delete(temp);
	    return;		
	}
    int cnt=1;
	node* temp=head;
	while(cnt!=pos)
	{
	   temp=temp->next;	
	   cnt++;
	}	
	if(temp->next==0)      // If the last node is to be deleted
	{
		temp->prev->next=0;
		delete(temp);
		return;
	}
	temp->next->prev=temp->prev;
	temp->prev->next=temp->next;
	delete(temp);
}

void displayList(node* head)
{
	node* temp=head;
	while(temp!=0)
	{
		cout<<temp->data<<"<=>";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	node* head=0;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	insertAtTail(head,5);
	//insertAtHead(head,0);
	displayList(head);
	deleteNode(head,5);
	displayList(head);
}
