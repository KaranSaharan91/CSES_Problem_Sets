#include<bits/stdc++.h>
using namespace std;
#define ll long long

void helper(vector<pair<int, ll>> a[], int i, vector<ll> &dist){
     priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
     vector<bool> vist(dist.size()+1, false);
     q.push({0, i});
     while(!q.empty()){
        auto t = q.top();
        q.pop();
        if(vist[t.second])continue;
        vist[t.second] = true;
        for(auto j : a[t.second]){
            if(dist[j.first] > dist[t.second]+j.second){
                dist[j.first] = dist[t.second]+j.second;
                q.push({dist[j.first], j.first});
            }
        }
     }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, ll>> a1[n+1];
    vector<pair<int, ll>> b1[n+1];
    vector<pair<pair<int, int>, ll>> edges;

    for(int i = 0; i<m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, w});
        a1[u].push_back({v, w});
        b1[v].push_back({u, w});
    }

    vector<ll> d1(n+1, LLONG_MAX);
    vector<ll> d2(n+1, LLONG_MAX);

    d1[1] = 0;
    d2[n] = 0;

    helper(a1, 1, d1);
    helper(b1, n, d2);

    ll ans = LLONG_MAX;

    for(int i = 0; i<m; i++){
        ll c = edges[i].second;
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        if(d1[u] != LLONG_MAX and d2[v] != LLONG_MAX)
        ans = min(ans, (d1[u]+d2[v]+c/2));
    }

    cout << ans << endl;
    return 0;

}