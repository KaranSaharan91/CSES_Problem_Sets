#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> &arr, int id, int sum, vector<vector<bool>> &dp, unordered_map<int, int> &mp){
     if(id == arr.size()){
        if(sum != 0){
         mp[sum]++;
        }
        return;
     }
     
     if(dp[sum][id])return;

     helper(arr, id+1, sum+arr[id], dp, mp);
     helper(arr, id+1, sum, dp, mp);

     if(sum != 0){
        mp[sum]++;
     }

     dp[sum][id] = true;

     return;
}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);

    int sum = 0;

    for(int i = 0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    vector<vector<bool>> dp (sum+1, vector<bool>(n, false));

    unordered_map<int, int> mp;

    

    helper(arr, 0, 0, dp, mp);

    int ans = 0;

    vector<int> v;

    for(auto i : mp){
        ans++;
        v.push_back(i.first);
    }

    sort(v.begin(), v.end());

    cout << ans << endl;

    for(int i : v){
        cout << i << " ";
    }
    cout << endl;

    return 0;

}

