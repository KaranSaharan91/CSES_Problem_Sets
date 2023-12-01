#include<bits/stdc++.h>
using namespace std;

// int helper(vector<int> &arr, int i, int x, vector<vector<int>>&ans){
//     if(x == 0)return 0;
//     if(x < 0 || i == arr.size())return -1;
   
//     if(ans[i][x] != -2)return ans[i][x];
    
//     int res = INT_MAX;
//     int t1 = helper(arr, i, x-arr[i], ans);
//     if(t1 != -1){
//         res = 1+t1;
//     }
//     int t2 = helper(arr, i+1, x-arr[i], ans);
//     if(t2 != -1){
//         res = min(res, t2+1);
//     }
//     int t3 = helper(arr, i+1, x, ans);
//     if(t3 != -1){
//         res = min(res, t3);
//     }
//     if(res != INT_MAX){
//         ans[i][x] = res;
//     }
//     else{
//         ans[i][x] = -1;
//     }
//     return ans[i][x];
// }

int table(vector<int> &arr, int n){
    vector<int> ans(n+1, INT_MAX);
    ans[0] = 0;

    for(int k = 1; k<=n; k++){
        for(int i = 0; i<arr.size(); i++){
            // if(k >= arr[i-1]){
            //     int t1 = ans[k-arr[i-1]][i];
            //     if(t1 != INT_MAX){
            //         ans[k][i] = (1+t1);
            //     }
            //     int t2 = ans[k-arr[i-1]][i-1];
            //     if(t2 != INT_MAX){
            //         ans[k][i] = min(ans[k][i], 1+t2);
            //     }
            // }
            // ans[k][i] = min(ans[k][i], ans[k][i-1]);
            int j = k-arr[i];
            if(j >= 0 and ans[j] != INT_MAX){
                ans[k] = min(ans[k], 1+ans[j]);
            }
        }
    }
    
    return ans[n];
}


int main(){

    int n, x;

    cin >> n >> x;

    vector<int> arr(n);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    // vector<vector<int>> ans(n, vector<int>(x+1, -2));

    int t = table(arr, x);

    if(t == INT_MAX){
        cout << -1 << endl;
        return 0;
    }

    cout << t << endl;

    return 0;

}