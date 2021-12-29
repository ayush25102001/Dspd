//Maximum path sum


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

int calc(node* n,int &val)
{
	if(n==0)
	{
		return 0;
	}
	else
	{
		int lh=calc(n->left,val);
		int rh=calc(n->right,val);
		val=max(val,n->data+lh+rh);
		return max(0,n->data+max(lh,rh));  //We do not return a negative sum
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
	int val=0;
	calc(root,val);
	cout<<val<<endl;
}
