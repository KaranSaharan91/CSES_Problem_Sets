#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;

    cin >> n >> m;

    vector<int> adj[n+1];

    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int> dist(n+1, INT_MAX);
    dist[1] = 1;

    queue<int> q;
    vector<int> v(n+1, -1);

    q.push(1);

    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int i = t;

        for(int j : adj[i]){
            if(dist[j] > dist[i]+1){
                dist[j] = dist[i]+1;
                v[j] = i;
                if(j == n)break;
                q.push(j);
            }
        }
    }

    if(dist[n] == INT_MAX){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << dist[n] << endl;
        vector<int> t;
        for(int i = n; i != -1; i = v[i]){
            t.push_back(i);
        }
        for(int i = t.size()-1; i>=0; i--){
            cout << t[i] << " ";
        }
        cout << endl;
    }

    return 0;
}