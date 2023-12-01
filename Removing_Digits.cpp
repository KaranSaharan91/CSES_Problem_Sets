#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    
    if(n <= 9){
        cout << 1 << endl;
        return 0;
    }

    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i<=9; i++){
        dp[i] = 1;
    }

    for(int i = 10; i<=n; i++){
        int t = i;
        while(t>0){
            int d = t%10;
            t = t/10;
            if(d == 0)continue;
            dp[i] = min(dp[i], 1+dp[i-d]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}