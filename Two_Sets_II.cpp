#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;

    ll sum = (n*(n+1))/2;

    if(sum%2 != 0){
        cout << 0 << endl;
        return 0;
    }

    vector<vector<ll> > dp((sum/2)+1, vector<ll>(n+1, 0));
    
    for(int i = 0; i<=n; i++){
        dp[0][i] = 1;
    }

    for(ll i = 1; i<=sum/2; i++){
        for(int j = 1; j<=n; j++){
            if(i >= j){
                dp[i][j] = dp[i-j][j-1];
            }
            dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
        }
    }
   
    ll ans = ((dp[sum/2][n])*500000004)%mod;

    cout << ans << endl;

    return 0;

}