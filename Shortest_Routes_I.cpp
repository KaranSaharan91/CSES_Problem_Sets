
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9+7;

int main(){

    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> adj[n+1];

    for(int i = 0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    
    }

    vector<ll> dist(n+1, LLONG_MAX);
    dist[1] = 0;

    priority_queue<pair<ll, int>> q;
    q.push({0, 1});
    
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        // if(t.first > dist[t.second])continue;
        if(t.first > dist[t.second])continue;
        for(auto i : adj[t.second]){
           if(dist[i.first] > (t.first+1ll*(i.second))){
                dist[i.first] = (t.first+1ll*(i.second));
                q.push({dist[i.first], i.first});
            }
        }
    }

    for(int i = 1; i<=n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;

}
// #include <bits/stdc++.h>

// using namespace std;
// typedef long long ll;
// const int maxN = 1e5;

// struct Edge { int v; ll w; };
// struct Node {
//     int id; ll dist;
//     friend bool operator<(const Node &a, const Node &b){
//         return a.dist > b.dist;
//     }
// };

// int N, M, a, b;
// ll dist[maxN+1], c;
// vector<Edge> G[maxN+1];
// priority_queue<Node> Q;

// int main(){
//     scanf("%d %d", &N, &M);
//     for(int i = 0; i < M; i++){
//         scanf("%d %d %lld", &a, &b, &c);
//         G[a].push_back({b, c});
//     }

//     memset(dist, 0x3f, sizeof(dist));
//     dist[1] = 0;
//     Q.push({1, 0});
//     while(!Q.empty()){
//         ll d = Q.top().dist;
//         int u = Q.top().id;
//         Q.pop();

//         if(d > dist[u]) continue;

//         for(Edge e : G[u]){
//             if(dist[e.v] > d+e.w){
//                 dist[e.v] = d+e.w;
//                 Q.push({e.v, d+e.w});
//             }
//         }
//     }

//     for(int i = 1; i <= N; i++)
//         printf("%lld%c", dist[i], (" \n")[i==N]);
// }