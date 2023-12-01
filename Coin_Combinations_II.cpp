// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// ll mod = 1e9+7;
 
// // ll helper(vector<int> &coin, int x, vector<ll> &ans){
// //     if(x < 0)return 0;
// //     if(x == 0)return 1;
 
// //     if(ans[x] != -1)return ans[x];
 
// //     ll res = 0;
 
// //     for(int i = 0; i<coin.size(); i++){
// //         ll t = helper(coin, x-coin[i], ans);
// //         res = (res+t)%mod;
// //     }
    
// //     ans[x] = res;
// //     return res;
// // }
 
// int main(){
//     int n, x;
//     cin >> n >> x;
 
//     vector<int> coin(n);
 
//     for(int i = 0;i<n; i++){
//         cin >> coin[i];
//     }

//     // sort(coin.begin(), coin.end());

//     vector<ll> dp(x+1, 0);
    
//     dp[0] = 1;

//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<=x-coin[i]; j++){
//                dp[j+coin[i]] = (dp[j+coin[i]]+dp[j])%mod;
//         }
//     }

//     cout << dp[x] << endl;

//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxX = 1e6;
const ll MOD = 1e9+7;

int N, X, c;
ll dp[maxX+1];

int main(){
    scanf("%d %d", &N, &X);

    dp[0] = 1;
    for(int i = 0; i < N; i++){
        scanf("%d", &c);
        for(int j = 0; j <= X-c; j++)
            dp[j+c] = (dp[j+c] + dp[j]) % MOD;
    }

    printf("%lld\n", dp[X]);
}