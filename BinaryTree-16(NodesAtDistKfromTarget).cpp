//NOTE:address of target node to be given by user along with k

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

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
   {
        unordered_map<TreeNode*,TreeNode*> parent;
        unordered_map<TreeNode*,int> visited;
        vector<int> ans;
        if(root==0)
        {
            return ans;
        }
        if(k==0)
        {
            ans.push_back(target->val);
            return ans;
        }
        queue<TreeNode*> qp;
        qp.push(root);
        parent[root]=0;
        while(!qp.empty())
        {
            TreeNode* temp=qp.front();
            if(temp->left!=0)
            {
                parent[temp->left]=temp;
                qp.push(temp->left);
            }
            if(temp->right!=0)
            {
                parent[temp->right]=temp;
                qp.push(temp->right);
            }
            qp.pop();
        }
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=1;
        int currlevel=0;
        while(!q.empty())
        {
            int s=q.size();
            if(currlevel++==k)
            {
                break;
            }
            for(int i=0;i<s;i++)
            {
               TreeNode*temp=q.front();
               q.pop();
               visited[temp]=1;
               if(temp->left!=0&&(!visited[temp->left]))
               {
                   q.push(temp->left);
               }
               if(temp->right!=0&&(!visited[temp->right]))
               {   
                  q.push(temp->right);
               }
               if(parent[temp]!=0&&(!visited[parent[temp]]))
               {
                  q.push(parent[temp]);
                } 
            }
        }
        vector<int> result;
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            result.push_back(x->val);
        }
        return result;
    }
    

