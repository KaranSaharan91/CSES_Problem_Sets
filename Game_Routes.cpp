#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;

ll dfs(vector<int> adj[], int i, int n, vector<ll> &dp){
    if(i == n){
        return 1;
    }
    if(dp[i] != -1)return dp[i];
    ll ans = 0;
    for(int j : adj[i]){
        ans = (ans+dfs(adj, j, n, dp))%mod;
    }
    dp[i] = ans;
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> adj[n+1];
    vector<ll> dp(n+1, -1);

    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    ll ans = dfs(adj, 1, n, dp);
    cout << ans << endl;

    return 0;
}