#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;

ll helper(vector<int> &arr, int id, int pr, int m,  vector<vector<ll> >&dp){   
   if(id == arr.size())return 1;

   if(pr != -1 and dp[id][pr] != -1)return dp[id][pr];
   
   if(arr[id] == 0){

      if(pr == -1){
        ll ans = 0;
        for(int i = 1; i<=m; i++){
            ans += helper(arr, id+1, i, m, dp);
            ans %= mod;
        }
        return ans;
      }

      ll ans = 0;

      if(pr < m){
        ans = helper(arr, id+1, pr+1, m, dp);
      }

      if(pr > 1){
        ans += helper(arr, id+1, pr-1, m, dp);
        ans %= mod;
      }

      ans += helper(arr, id+1, pr, m, dp);
      ans %= mod;
     
      dp[id][pr] = ans;
      return ans;

   }

   if(pr == -1){
      return helper(arr, id+1, arr[id], m, dp);
   }

   if(abs(pr-arr[id]) <= 1){
      dp[id][pr] = helper(arr, id+1, arr[id], m, dp);
      return dp[id][pr];
   }

   dp[id][pr] = 0;
   return 0;
}


int main(){
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    
    vector<vector<ll> > dp(n, vector<ll>(m+1, -1));

    ll ans = helper(arr, 0, -1, m, dp);

    cout << ans << endl;

    return 0;
}