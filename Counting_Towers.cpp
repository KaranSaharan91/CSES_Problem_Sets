#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<vector<ll> > dp(n+1, vector<ll>(2, 0));
        
        cout << dp[n][2] << endl;
    }

    return 0;
}