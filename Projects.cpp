#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
     return (a.first.second < b.first.second);
}

ll helper(vector<pair<pair<int, int>, int> > &arr, int id, int pr, vector<ll> &dp){
   if(id == arr.size())return 0;

   if(pr < arr[id].first.first and dp[id] != -1){
      return dp[id];
   }
   
   if(pr < arr[id].first.first){
      ll t1 = arr[id].second + helper(arr, id+1, arr[id].first.second, dp);
      ll t2 = helper(arr, id+1, pr, dp);
      dp[id] = max(t1, t2);
      return dp[id];
   }

   else{
       return helper(arr, id+1, pr, dp);
   }

}

// int findx(vector<pair<pair<int, int>, int> >&arr, int s, int e, int x){
    
//     int j = -1;
//     while(s <= e){
//         int mid = s+(e-s)/2;
//         if(arr[mid].first.second < x){
//             j = mid;
//             s = mid+1;
//         }
//         else{
//             e = mid-1;
//         }
//     }
//     return j;
// }

// ll solve(vector<pair<pair<int, int>, int> >&arr, int n){
//     vector<ll> dp(n+1, 0);

//     for(int i = 1; i<=n; i++){
//         ll opt1 = dp[i-1];
//         ll opt2 = arr[i-1].second;
//         int j = findx(arr, 0, i-2, arr[i-1].first.first);
//         if(j!=-1){
//             opt2 += dp[j+1];
//         }
//         dp[i] = max(opt1, opt2);
//     }

//     return *max_element(dp.begin(), dp.end());
// }

int main(){

    int n;
    cin >> n;

    vector<pair<pair<int, int>, int> > arr;

    for(int i = 0; i<n; i++){
        int a, b;
        int c;
        cin >> a >> b >> c;
        arr.push_back({{a, b}, c});
    }

    vector<ll> dp(n+1, -1);
    dp[n+1] = 0;

    sort(arr.begin(), arr.end(), cmp);

    ll ans = helper(arr, 0, 0, dp);

    // ll ans = solve(arr, n);

    cout << ans << endl;

    return 0;

}