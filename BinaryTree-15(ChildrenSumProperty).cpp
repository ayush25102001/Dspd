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
void preorder(node* root)
{
	if(root==0)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void childrenSum(node* root)
{
	if(root==0)
	{
		return ;
	}
	int sum=0;
	if(root->left)
	{
		sum+=root->left->data;
	}
	if(root->right)
	{
		sum+=root->right->data;
	}
	if(sum>=root->data)
	{
		root->data=sum;
	}
	else
	{
		if(root->left)
	    {
		    root->left->data=root->data;
	    }
	    if(root->right)
	    {
	    	root->right->data=root->data;
		}
	}
	childrenSum(root->left);
	childrenSum(root->right);
	int tot=0;
	if(root->left)
	{
		tot+=root->left->data;
	}
	if(root->right)
	{
		tot+=root->right->data;
	}
	if(root->left||root->right)
	{
		root->data=tot;
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
	cout<<"Before"<<endl;
	preorder(root);
	cout<<endl;
	childrenSum(root);
	cout<<"After"<<endl;
	preorder(root);
}
