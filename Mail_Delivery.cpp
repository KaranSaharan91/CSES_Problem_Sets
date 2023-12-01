#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n+1];
    vector<int> dg(n+1, 0);

    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b; 
        dg[a]++;
        dg[b]++;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    int f = 0;
    for(int i = 1; i<=n; i++){
        if(dg[i]&1){
            cout << "IMPOSSIBLE" << endl;
            f = 1;
            break;
        }
    }
    
    if(f == 0){
    
    stack<int> s;
    vector<bool> vist(m, false);
    vector<int> ans;
    s.push(1);

    while(!s.empty()){
         int u = s.top();
         if(dg[u]){
             while(!adj[u].empty()){
                  int v = adj[u].back().first;
                  int id = adj[u].back().second;
                  adj[u].pop_back();
                  if(!vist[id]){
                     vist[id] = true;
                     s.push(v);
                     dg[u]--;
                     dg[v]--;
                     break;
                  }
             }
         }
         else{
            ans.push_back(u);
            s.pop();
         }
    }
    
    if(ans.size() == m+1){
        for(int i : ans){
            cout << i << " ";
        }
        cout << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
    
    }

    return 0;
}