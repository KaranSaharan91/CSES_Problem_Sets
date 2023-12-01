#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n, m, k;

    cin >> n >> m >> k;

    vector<pair<ll, int> > adj[n+1];

    for(int i = 0; i<m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    vector<ll> ans;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > q;

    
    vector<int> cnt(n+1, 0);
    q.push({0, 1});

    while(!q.empty()){
        auto t = q.top();
        q.pop();

        int x = t.second;
        ll d = t.first;
        cnt[x]++;
        if(x == n){
            ans.push_back(d);
            if(cnt[x] == k)break;
        }
        if(cnt[x] <= k){
        for(auto j : adj[x]){
            q.push({(d+j.first), j.second});
        }
        }
    }

    sort(ans.begin(), ans.end());
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
// #include <bits/stdc++.h>

// using namespace std;
// typedef long long ll;
// typedef pair<int,ll> edge;
// typedef pair<ll,int> node;
// const int maxN = 2e5+1;

// int N, M, K, cnt[maxN];
// vector<edge> G[maxN];
// priority_queue<node, vector<node>, greater<node>> Q;

// int main(){
//     scanf("%d %d %d", &N, &M, &K);
//     for(int i = 0, a, b, c; i < M; i++){
//         scanf("%d %d %d", &a, &b, &c);
//         G[a].push_back({b, c});
//     }

//     Q.push({0, 1});
//     while(!Q.empty()){
//         ll d = get<0>(Q.top());
//         int u = get<1>(Q.top());
//         Q.pop();

//         cnt[u]++;
//         if(u == N){
//             printf("%lld%c", d, (" \n")[cnt[u]==K]);
//             if(cnt[u] == K) return 0;
//         }

//         if(cnt[u] <= K){
//             for(edge e : G[u]){
//                 int v = e.first;
//                 ll w = e.second;
//                 Q.push({d+w, v});
//             }
//         }
//     }
// }