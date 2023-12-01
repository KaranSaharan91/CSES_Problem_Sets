#include<bits/stdc++.h>
using namespace st;
#define ll long long


int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, ll>> adj[n+1];
    for(int i = 0; i<m; i++){
        int a, b; ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    return 0;
}