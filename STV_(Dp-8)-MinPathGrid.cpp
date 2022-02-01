#include<iostream>
#include<vector>
using namespace std;
	int solve(int i,int j,vector<vector<int> > grid,vector<vector<int> > dp){
        if(i<0||(j<0)){
            return 100000;
        }
        if(i==0&&(j==0)){
            return grid[0][0];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else{
            int up=grid[i][j]+solve(i-1,j,grid,dp);
            int left=grid[i][j]+solve(i,j-1,grid,dp);
            return dp[i][j]=min(up,left);
        }
    }
    int minPathSum(vector<vector<int> > grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int> > dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
    int main(){
	int m,n;
	cout<<"Enter m and n-"<<endl;
	cin>>m>>n;
	printf("ENTER GRID:");
	vector<vector<int> > grid(m,vector<int> (n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
		}
	}
	cout<<minPathSum(grid)<<endl;
    }
    
