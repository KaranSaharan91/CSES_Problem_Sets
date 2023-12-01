#include<bits/stdc++.h>
using namespace std;



int main(){

   int n, m;

    cin >> n >> m;

    vector<int> adj[n+1];

    vector<int> ind(n+1, 0);

    queue<int> q;

    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ind[b]++;
    }

    for(int i = 1; i<=n; i++){
        if(ind[i] == 0)q.push(i);
    }

    int cnt = 0;
    vector<int> ans;

    while(!q.empty()){

          int t = q.front();

          q.pop();

          ans.push_back(t);

          cnt++;

          for(int j : adj[t]){
              ind[j]--;
              if(ind[j] == 0)q.push(j);

          }
    }

    if(cnt == n){
        for(int i : ans){
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }
    
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}