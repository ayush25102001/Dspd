//TOP/BOTTOM/LEFT/RIGHT


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

void topview(node* n)
{
	vector<int> ans;
	queue<pair<node*,int>> q;
	q.push({n,0});
	map <int,int> mp;
	while(!q.empty())
	{
		auto it=q.front();
		q.pop();
		n=it.first;
		int line=it.second;
		if(mp.find(line)==mp.end())
		{
		      mp[line]=n->data;
		}
		if(n->left!=0)
		{
			q.push({n->left,line-1});
		}
		if(n->right!=0)
		{
			q.push({n->right,line+1});
		}
	}
	for(auto x:mp)
	{
		ans.push_back(x.second);
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

void bottomview(node* n)
{
	vector<int> ans;
	queue<pair<node*,int>> q;
	q.push({n,0});
	map <int,int> mp;
	while(!q.empty())
	{
		auto it=q.front();
		q.pop();
		n=it.first;
		int line=it.second;
		mp[line]=n->data;
		if(n->left!=0)
		{
			q.push({n->left,line-1});
		}
		if(n->right!=0)
		{
			q.push({n->right,line+1});
		}
	}
	for(auto x:mp)
	{
		ans.push_back(x.second);
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}


void left(node* n,vector<int> &res,int level)
    {
        if(n==0)
        {
            return;
        }
        else
        {
            if(res.size()==level)
            {
                res.push_back(n->data);
            }
            
            left(n->left,res,level+1);
            left(n->right,res,level+1);
        }
    }
vector<int> leftView(node *root)
{
   vector<int> res;
   left(root,res,0);
   return res;
}

void right(node* n,vector<int> &res,int level)
    {
        if(n==0)
        {
            return;
        }
        else
        {
            if(res.size()==level)
            {
                res.push_back(n->data);
            }
            right(n->right,res,level+1);
            right(n->left,res,level+1);
        }
    }
vector<int> rightView(node *root)
{
   vector<int> res;
   right(root,res,0);
   return res;
}

int main()
{
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	bottomview(root);
	topview(root);
    vector<int> ans=leftView(root);
    for(int i=0;i<ans.size();i++)
    {
    	cout<<ans[i]<<" ";
	}
	cout<<endl;
	vector<int> ansr=rightView(root);
	for(int i=0;i<ansr.size();i++)
    {
    	cout<<ansr[i]<<" ";
	}
	
}
