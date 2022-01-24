//STV_(Dp-3)-Frog(B)-k forward

#include<bits/stdc++.h>
using namespace std;
void solve(int n, int dp[], int jump[], int k){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if ((i - j) >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(jump[i] - jump[i - j]));
            }
        }
    }
}
int main(){
  int n, k;
    cin >> n >> k;
  int jump[n];
    for (int i = 0; i < n; i++) {
        cin >> jump[i];
    }
  int dp[n];
    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    solve(n - 1, dp, jump, k);
    cout << dp[n - 1] << endl;
}

