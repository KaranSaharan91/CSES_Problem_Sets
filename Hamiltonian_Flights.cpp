// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// ll mod = 1e9+7;

// int main(){
//     int n, m;
//     cin >> n >> m;

//     vector<int> adj[n];
//     for(int i = 0; i<m; i++){
//         int a, b;
//         cin >> a >> b;
//         adj[a-1].push_back(b-1);
//     }

//     queue<pair<int, int>> q;
//     q.push({0, 1});

//     vector<vector<ll>> dp(n, vector<ll>((1<<n), 0));
//     dp[0][1] = 1;

//     vector<vector<int>> vist(n, vector<int>((1<<n), 0));
//     vist[0][1] = 1;


//     while(!q.empty()){
//         int u = q.front().first;
//         int mask = q.front().second;
//         q.pop();
//         if(u != n-1){
//         for(int i : adj[u]){
//            if((mask&(1<<i)))continue;
//            int temp = mask|(1<<i);
//            dp[i][temp] += dp[u][mask];
//            dp[i][temp] %= mod;
//            if(vist[i][temp] == 0){
//              vist[i][temp] = 1;
//              q.push({i, temp});
//            }
//         }
//         }
//     }

//     cout << dp[n-1][(1<<n)-1] << endl;

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxN = 20;
const int SIZE = 1<<maxN;
const ll MOD = 1e9+7;

int N, M;
bool inqueue[maxN][SIZE];
ll dp[maxN][SIZE];
vector<int> G[maxN];
queue<pii> Q;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a-1].push_back(b-1);
    }

    dp[0][1] = 1;
    Q.push({0, 1});
    inqueue[0][1] = true;
    while(!Q.empty()){
        int u = Q.front().first;
        int mask = Q.front().second;
        Q.pop();

        if(u != N-1){
            for(int v : G[u]){
                int newMask = mask|(1<<v);
                if((mask&(1<<v)) == 0){
                    dp[v][newMask] += dp[u][mask];
                    dp[v][newMask] %= MOD;
                    if(!inqueue[v][newMask]){
                        Q.push({v, newMask});
                        inqueue[v][newMask] = true;
                    }
                }
            }
        }
    }

    printf("%lld\n", dp[N-1][(1<<N)-1]);
}