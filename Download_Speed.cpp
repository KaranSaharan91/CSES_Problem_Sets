#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, ll>> adj[n+1];

    for(int i = 0; i<m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    queue<pair<ll, int>> q;
    vector<ll> dist(n+1, 0);
    q.push({0, 1});
    dist[1] = INT_MAX;

    while(!q.empty()){
        auto t = q.front();
        q.pop();

        if(t.second == n){
            continue;
        }

        for(auto i : adj[t.second]){
            if(dist[i.first] < dist[t.second]+i.second){
                dist[i.first] = dist[t.second]+i.second;
                q.push({dist[i.first], i.first});
            }
        }
    }

    cout << dist[n-1] << endl;
    return 0;
}