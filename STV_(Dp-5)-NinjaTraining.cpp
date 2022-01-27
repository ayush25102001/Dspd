#include<iostream>
#include<vector>
using namespace std;
int solve(int n,vector<vector<int> > &p,int last,int dp[][4]){
    if(n==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,p[0][task]);
            }
        }
        return dp[0][last]=maxi;
    }
    if(dp[n][last]!=-1){
        return dp[n][last];
    }
    int maxi=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int curr=solve(n-1,p,task,dp)+p[n][task];
            maxi=max(maxi,curr);
        }
    }
    return dp[n][last]=maxi;
}

int ninjaTraining(int n, vector<vector<int> > &p)
{
    int last=3;
    int dp[n][4];
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            dp[i][j]=-1;
        }
    }
    solve(n-1,p,last,dp);
    return dp[n-1][3];
}

int main(){
	int n;
	cin>>n;
	vector<vector<int> > p;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>p[i][j];
		}
	}
	cout<<ninjaTraining(n,p)<<endl;
}
