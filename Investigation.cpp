#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9+7;

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
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

    map<int, pair<ll, pair<int, int>>> mp;
    mp[1] = {1, {0, 0}};
    q.push({0, 1});
    
    vector<ll> dist(n+1, LLONG_MAX);
    
    dist[1] = 0;

    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int x = t.second;
        ll d = t.first;
        if(x == n){
            if(d > dist[n])break;
            continue;
        }
        if(d > dist[x])continue;
        for(auto j : adj[x]){
            if(dist[j.first] > dist[x]+j.second){
                dist[j.first] = dist[x]+j.second;
                mp[j.first].first = mp[x].first;
                mp[j.first].second.first = mp[x].second.first+1;
                mp[j.first].second.second = mp[x].second.second+1;
                q.push({dist[j.first], j.first});
            }
            else if(dist[j.first] == dist[x]+j.second){
                mp[j.first].first = (mp[j.first].first+mp[x].first)%mod;
                mp[j.first].second.first = min(mp[x].second.first+1, mp[j.first].second.first);
                mp[j.first].second.second = max(mp[x].second.second+1, mp[j.first].second.second);
            }
        }
    }

    cout << dist[n] << " ";
    cout << mp[n].first << " ";
    cout << mp[n].second.first << " ";
    cout << mp[n].second.second << " ";
    cout << endl;


    return 0;

}