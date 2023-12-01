#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;

int main(){
    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> value(n);

    for(int i = 0; i<n; i++){
        cin >> price[i];
    }

    for(int i = 0; i<n; i++){
        cin >> value[i];
    }
    
    vector<int > dp(x+1, 0);

    for(int i = 0; i<n; i++){
        for(int j = x-price[i]; j>=0; j--){
            dp[j+price[i]] = max(dp[j+price[i]], dp[j]+value[i]);
        }
    }

    int ans = *max_element(dp.begin(), dp.end());

    cout << ans << endl;

    return 0;
}
// #include <bits/stdc++.h>

// using namespace std;
// const int maxN = 1000;
// const int maxX = 1e5;

// int N, X, h[maxN], s[maxN], dp[maxX+1];

// int main(){
//     scanf("%d %d", &N, &X);
//     for(int i = 0; i < N; i++)  scanf("%d", &h[i]);
//     for(int i = 0; i < N; i++)  scanf("%d", &s[i]);

//     fill(dp+1, dp+X+1, -1);
//     for(int i = 0; i < N; i++)
//         for(int j = X-h[i]; j >= 0; j--)
//             if(dp[j] != -1)
//                 dp[j+h[i]] = max(dp[j+h[i]], dp[j]+s[i]);

//     for(int i = 1; i <= X; i++)
//         dp[i] = max(dp[i], dp[i-1]);
//     printf("%d\n", dp[X]);
// }