#include<iostream>
#include<vector>
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
int trace(node* n,int a,int b)
{
	if(n==0)
	{
		return 0;
	}
	if(n->data==a||n->data==b)
	{
		return n->data;
	}
	int lchk=trace(n->left,a,b);
	int rchk=trace(n->right,a,b);
	if(lchk==0)
	{
		return rchk;
	}
	else if(rchk==0)
	{
		return lchk;
	}
	else
	{
		return n->data;
	}
}
int lca(node* n,int a,int b)
{
	if(n==0)
	{
		return 0;
	}
	if(n->data==a||n->data==b)
	{
		return n->data;
	}
	return trace(n,a,b);
}
int main()
{
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	//inorder(root);
	int ans=lca(root,4,5);
	if(ans!=0)
	{
		cout<<ans<<endl;
	}
}
