#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
 int solve(vector<int>& a) {
        int n=a.size();
        int dp[n];
        memset(dp,-1,n);
        dp[0]=a[0];
        for(int i=1;i<n;i++){
            int pick=a[i];
            if(i>1){
                pick+=dp[i-2];
            }
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	cout<<solve(a)<<endl;
}
