#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;

// ll helper(vector<int> &coin, int x, vector<ll> &ans){
//     if(x < 0)return 0;
//     if(x == 0)return 1;

//     if(ans[x] != -1)return ans[x];

//     ll res = 0;

//     for(int i = 0; i<coin.size(); i++){
//         ll t = helper(coin, x-coin[i], ans);
//         res = (res+t)%mod;
//     }

//     ans[x] = res;
//     return res;
// }

int main(){
    int n, x;
    cin >> n >> x;

    vector<int> coin(n);

    for(int i = 0;i<n; i++){
        cin >> coin[i];
    }
    vector<ll> ans(x+1, 0);
    
    ans[0] = 1;

    for(int k = 1; k<=x; k++){
        ll cnt = 0;
        for(int i = 0; i<n; i++){
          if(k >= coin[i]){
           cnt += ans[k-coin[i]];
          }
        }
        ans[k] = cnt%mod;
    }
   
    cout << ans[x] << endl;
    return 0;

}