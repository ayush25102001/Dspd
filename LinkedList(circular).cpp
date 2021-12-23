//DOUBLY LINKED LIST:
// 1. Insertion(head+tail).
// 2. Deletion.

#include<iostream>
using namespace std;
class node{
	public:
		int data;
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
		head->next=0;
		return;
	}
	node* temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=n;
	n->next=head;
	head=n;
}

void insertAtTail(node* &head,int val)
{
	node* n=new node(val);
	if(head==0)
	{
		head=n;
		head->next=head;
		return;
	}
	node* temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=n;
	n->next=head;
}

void deleteNode(node* &head,int k)
{
	if(k==1)
	{
		node* temp=head;
	    while(temp->next!=head)
	    {
		    temp=temp->next;
	    }
	    temp->next=head->next;
	    head->next=0;
	    head=temp->next;
	    return;
	}
	int cnt=1;
	node* temp=head;
	while(cnt!=(k-1))
	{
		temp=temp->next;
		cnt++;
	}
	temp->next=temp->next->next;
	return;
}


void displayList(node* head)
{
	node* temp=head;
	while(temp->next!=0)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
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
	//displayList(head);
	//deleteNode(head,5);
	//displayList(head);
}
