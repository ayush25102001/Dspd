#include<bits/stdc++.h>
using namespace std;
void frogJump(int n, vector<int> &h,vector<int> &dp)
{
   for(int i=1;i<=n;i++){
        int lh=dp[i-1]+abs(h[i]-h[i-1]);
        int rh=INT_MAX;
        if(i>1){
             rh=dp[i-2]+abs(h[i]-h[i-2]);
        }
        dp[i]=min(lh,rh);
      }

}
int main(){
  int n;
  cin>>n;
  vector<int> h;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    h.push_back(x);
  }
   vector<int> dp;
    for(int i=0;i<n;i++){
          dp.push_back(0);
    }
  frogJump(n-1,h,dp);
  cout<<dp[n-1]<<endl;
}

