//BINARY TREE
// Traversals - levelorder



#include<iostream>
#include<queue>
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

void levelorder(node* root)
{
	queue <node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* n=q.front();
		if(n->left!=0)
		{
			q.push(n->left);
		}
		if(n->right!=0)
		{
			q.push(n->right);
		}
		cout<<n->data<<" ";
		q.pop();
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
	levelorder(root);
}
