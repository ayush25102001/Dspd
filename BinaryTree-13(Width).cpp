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
int width(node* root) 
    {
        if(root==0)
        {
            return 0;
        }
        queue<pair<node*,int> > q;
        q.push({root,0});
        int maxq=0;
        while(!q.empty())
        {
            int mul=q.front().second;
            int s=q.size();
            if(s==1)
            {
                int cur=q.front().second-mul;
                auto x=q.front();
                maxq=max(maxq,1);
                q.pop();
                if(x.first->left!=0)
                {
                    q.push({x.first->left,2*(cur)+1});
                }
                if(x.first->right!=0)
                {
                    q.push({x.first->right,2*(cur)+2});
                }
            }
            else
            {
                
                int a=0;
                int b=0;
                for(int i=0;i<s;i++)
                {
                    int cur=q.front().second-mul;
                    auto x=q.front();
                    if(i==0)
                    {
                        a=x.second;
                    }
                    if(i==s-1)
                    {
                        b=x.second;
                    }
                    if(x.first->left!=0)
                    {
                       q.push({x.first->left,2*(cur)+1});
                    }
                    if(x.first->right!=0)
                    {
                       q.push({x.first->right,2*(cur)+2});
                    }
                    q.pop();
                }
                maxq=max(maxq,b-a+1);
            }
        }
        return maxq;
    }

int main()
{
	node* root=new node(1);
	root->left=new node(2);
	root->right=new node(3);
	root->left->left=new node(4);
	root->left->right=new node(5);
	root->right->left=new node(6);
	cout<<width(root)<<endl;
	
}
