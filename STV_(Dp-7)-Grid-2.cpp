#include<iostream>
#include<vector>
using namespace std;
int compute(int i,int j,vector<vector<int> > &dp,vector<vector<int> > grid){
        if((i==0)&&(j==0)){
            return 1;
        }
        if((i<0)||(j<0)){
            return 0;
        }
        if(grid[i][j]==-1){
        	return 0;
		}
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=compute(i-1,j,dp,grid);
        int left=compute(i,j-1,dp,grid);
        return dp[i][j]=up+left;
    }
int uniquePaths(int m, int n, vector<vector<int> > grid){
	 vector<vector<int> > dp(m,vector<int>(n,-1));
     return compute(m-1,n-1,dp,grid);
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
	cout<<uniquePaths(m,n,grid)<<endl;
}
