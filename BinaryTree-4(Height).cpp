#include<bits/stdc++.h>
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

int height(node* root)
{
	node* temp=root;
	if(temp==0)
	{
		return 0;
	}
	else
	{
		return (1+max(height(temp->left),height(temp->right)));
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
	int ans=height(root);
	cout<<ans<<endl;
	
}
