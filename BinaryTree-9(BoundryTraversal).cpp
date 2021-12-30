//Boundry Traversal(recheck)


#include<iostream>
#include<vector>
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


void goleft(node* n,vector<int> &l)
{
	if(n->left==0&&n->right==0)
	{
		return;
	}
	else if(n->left!=0)
	{
		goleft(n->left,l);
		l.push_back(n->data);
	}
	else
	{
		goleft(n->right,l);
		l.push_back(n->data);
	}
}

void getleaves(node* n,vector<int> &l)
{
	if(n->left==0&&n->right==0)
	{
		l.push_back(n->data);
	}
	if(n->left)
	{
		getleaves(n->left,l);
	}
	if(n->right)
	{
		getleaves(n->right,l);
	}
}

void goright(node* n,vector<int> &l)
{
	if(n->left==0&&n->right==0)
	{
		return;
	}
	else if(n->right!=0)
	{
		goright(n->right,l);
		l.push_back(n->data);
	}
	else
	{
		goright(n->left,l);
		l.push_back(n->data);
	}
}

vector<int> boundry(node* n)
{
	node* ll=n->left;
	node* r=n->right;
	vector<int> l;
	l.push_back(n->data);
	goleft(ll,l);
	getleaves(n,l);
	goright(r,l);
	return l;
}

int main()
{
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	vector<int> ans=boundry(root);
	for(int i=0;i<ans.size();i++)
	{
	       cout<<ans[i]<<" ";
	}
	
}
