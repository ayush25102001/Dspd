//Diameter of a binary tree

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
int diameter(node* n,int &dia)
{
	if(n==0)
	{
		return 0;
	}
	else
	{
		int lh=diameter(n->left,dia);
		int rh=diameter(n->right,dia);
		dia=max(dia,1+lh+rh);
		return (1+max(lh,rh));
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
	int dia=0;
	diameter(root,dia);
	cout<<dia-1<<endl;
}
