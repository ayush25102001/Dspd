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
int findPath(node* root,vector<int>& ans,int val)
{
	if(root==0)
	{
		return 0;
	}
	ans.push_back(root->data);
	if(root->data==val)
	{
		return 1;
	}
	if(findPath(root->left,ans,val)||findPath(root->right,ans,val))
	{
		return 1;
	}
	else
	{
		ans.pop_back();
		return 0;
	}
}

vector<int> getPath(node* root,int val)
{
	vector<int> ans;
	if(root==0)
	{
		return ans;
	}
	findPath(root,ans,val);
	return ans;
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
	vector<int> sol=getPath(root,7);
	if(sol.size()==0)
	{
		cout<<"NoPathExists"<<endl;
	}
	for(int i=0;i<sol.size();i++)
	{
		cout<<sol[i]<<" ";
	}
}
