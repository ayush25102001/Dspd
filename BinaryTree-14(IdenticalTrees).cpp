#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
		node(int val)
		{
			data=val;
			left=0;
			right=0;
		}
};
int checkIdentical(node* p,node* q)
{
	if(p==0||q==0)
	{
		if(p==q)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(p->data!=q->data)
	{
		return 0;
	}
	return checkIdentical(p->left,q->left)&&checkIdentical(p->right,q->right);
}
int main()
{
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	node* rot=new node(1);
	rot->left=new node(2);
	rot->right=new node(3);
	rot->left->left=new node(4);
	rot->left->right=new node(5);
	rot->right->left=new node(6);
	if(checkIdentical(root,rot))
	{
		cout<<"Identical"<<endl;
	}
	else
	{
		cout<<"Not Identical"<<endl;
	}
}
