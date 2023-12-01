#include<bits/stdc++.h>

using namespace std;

// int helper(int n, int m, vector<vector<int> > &dp){
//     if(n == m) return 0;

//     if(dp[n][m] != -1)return dp[n][m];

//     int ans = INT_MAX;
//     for(int i = 1; i<n; i++){
//         ans = min(ans, 1+helper(i, m, dp)+helper(n-i, m, dp));
//     }
//     for(int i = 1; i<m; i++){
//         ans = min(ans, 1 + helper(n, i, dp) + helper(n, m-i, dp));
//     }
//     dp[n][m] = ans;
//     return ans;
// }

int main(){
    
    int n, m;

    cin >> n >> m;

    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));

    // int ans = helper(n, m, dp);

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(i == j){
                dp[i][j] = 0;
            }
            else{
                int ans = INT_MAX;
                for(int k = 1; k<i; k++){
                    ans = min(ans, 1+dp[k][j]+dp[i-k][j]);
                }
                for(int k = 1; k<j; k++){
                    ans = min(ans, 1+dp[i][k]+dp[i][j-k]);
                }
                dp[i][j] = ans;
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}