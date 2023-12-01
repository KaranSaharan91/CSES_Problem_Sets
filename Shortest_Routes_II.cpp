#include<bits/stdc++.h>
using namespace std;

#define ll long long



int main(){
    int n, m, Q;
    cin >> n >> m >> Q;

    vector<vector<ll>> dist(n+1, vector<ll>(n+1, LLONG_MAX));

    for(int i = 0; i<m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        if(dist[a][b] > c){
        dist[a][b] = c;
        dist[b][a] = c;
        }
    }

    for(int i = 1; i<=n; i++){
        dist[i][i] = 0;
    }

    for(int i = 1; i<=n; i++){
       for(int j = 1; j<=n; j++){
        for(int k = 1; k<=n; k++){
        if(dist[j][i] != LLONG_MAX and dist[i][k] != LLONG_MAX)
        dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
        }
       }
    }

    for(int i = 0; i<Q; i++){
       int a, b;
       cin >> a >> b;
       if(dist[a][b] == LLONG_MAX){
        cout << -1 << endl;
       }
       else{
        cout << dist[a][b] << endl;
       }
    }

    return 0;

}