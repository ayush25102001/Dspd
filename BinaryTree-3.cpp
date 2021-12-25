//BINARY TREE
// Traversals - preorder/inorder/postorder
// iterative

#include<iostream>
#include<vector>
#include<stack>
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
	stack <node*> s;
	s.push(root);
	while(!s.empty())
	{
		node* n=s.top();
		cout<<n->data<<" ";
		s.pop();
		if(n->right!=0)
		{
			s.push(n->right);
		}
		if(n->left!=0)
		{
			s.push(n->left);
		}
	}
}

void inorder(node* root)
{
	stack <node*> s;
	node* n=root;
	do
	{
		if(n!=0)
		{
			s.push(n);
			n=n->left;
		}
		else
		{
			n=s.top();
			cout<<n->data<<" ";
			s.pop();
			n=n->right;
		}
	}while(!s.empty()||n!=0);
}

void postorder(node* root)
{
	stack <node*> s1;
	stack <node*> s2;
	s1.push(root);
	while(!s1.empty())
	{
		node* n=s1.top();
		s2.push(n);
		s1.pop();
		if(n->left!=0)
		{
			s1.push(n->left);
		}
		if(n->right!=0)
		{
			s1.push(n->right);
		}
    }
	while(!s2.empty())
	{
		cout<<s2.top()->data<<" ";
		s2.pop();
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
	inorder(root);
}

