
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

vector<vector<int> > spiral(node* n)
{
	queue<node*> q;
	q.push(n);
	int ltr=1;
	vector<vector<int> > ans;
	while(!q.empty())
	{
		int s=q.size();
		vector<int> row(s);
		if(ltr)
		{
			for(int i=0;i<s;i++)
			{
				node* temp=q.front();
				q.pop();
				row[i]=temp->data;
				if(temp->left!=0)
				{
					q.push(temp->left);
				}
				if(temp->right!=0)
				{
					q.push(temp->right);
				}
			}
			ltr=0;
			ans.push_back(row);
		}
		else
		{
			for(int i=0;i<s;i++)
			{
				node* temp=q.front();
				q.pop();
				row[s-i-1]=temp->data;
				if(temp->left!=0)
				{
					q.push(temp->left);
				}
				if(temp->right!=0)
				{
					q.push(temp->right);
				}
			}
			ltr=1;
			ans.push_back(row);
		}
	}
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
	vector<vector<int> > ans=spiral(root);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
	}
	
}
