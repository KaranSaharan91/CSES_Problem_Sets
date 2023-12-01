#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int n;
    cin >> n;

    vector<ll> arr(n);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    vector<vector<ll> > dp(n, vector<ll>(n, 0));

    for(int j = 0; j<n; j++){
            for(int k = j, i = 0; k<n and i<n-j; k++, i++){
                if(i == k){
                    dp[i][k] = arr[i];
                }
                else if(i+1 == k){
                    dp[i][k] = max(arr[i], arr[k]);
                }
                else{
                    ll t1 = arr[i]+min(dp[i+2][k], dp[i+1][k-1]);
                    ll t2 = arr[k]+min(dp[i][k-2], dp[i+1][k-1]);
                    dp[i][k] = max(t1, t2);
                }
            }
    }

    cout << dp[0][n-1] << endl;
    return 0;
}