#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 0x3f3f3f3f3f3f3f3f;

void dfs(vector<int> a[], vector<bool> &vist, int i){
    vist[i] = true;
    for(auto j : a[i]){
        if(!vist[j]){
            dfs(a, vist,  j);
        }
    }
}

struct edge{
     int u, v; ll cost;
};

int main(){

    int n, m;

    cin >> n >> m;

    vector<int> a[n+1];
    vector<int> b[n+1];

    vector<edge> E;
    
    for(int i = 0; i<m; i++){
        int u, v; ll w;
        cin >> u >> v >> w;
        edge e;
        e.u = u;
        e.v = v;
        e.cost = -w;
        E.push_back(e);
        a[u].push_back(v);
        b[v].push_back(u);
    }

    vector<bool> vist(n+1);
    vector<bool> vist1(n+1);

    dfs(a, vist, 1);
    dfs(b, vist1, n);

    vector<ll> dist(n+1, INF);
    dist[1] = 0;
    int flag = 0;
    for(int i = 1; i<=n; i++){
       flag = 0;
       for(edge j : E){
           if(vist[j.u] and vist1[j.v] and dist[j.v] > dist[j.u]+j.cost){
            flag = 1;
            dist[j.v] = dist[j.u]+j.cost;
           }
       }
    }

    if(flag == 1){
       cout << -1 << endl;
    }
    else{
        cout << dist[n]*(-1) << endl;
    }

    return 0;
}