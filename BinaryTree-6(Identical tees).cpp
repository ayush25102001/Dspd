//Identical binary trees


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
int check(node* n,node* nn)
{
	if(n==0||nn==0)
	{
		if(n==nn)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return ((n->data==nn->data)&&(check(n->left,nn->left))&&(check(n->right,nn->right)));
	}
}
int main()
{
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	node* roott=new node(1);
	roott->left=new node(2);
	roott->right=new node(3);
	roott->left->left=new node(4);
	roott->left->right=new node(5);
	roott->right->left=new node(6);
	if(check(root,roott))
	{
		cout<<"IDENTICAL";
	}
	else
	{
		cout<<"NOT IDENTICAL";
	}
}
