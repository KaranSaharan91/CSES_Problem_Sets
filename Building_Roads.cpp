#include<bits/stdc++.h>
using namespace std;

void helper(vector<int> adj[], int i, int p, vector<bool> &vist, vector<int>&head){
     vist[i] = 1;
     head[i] = p;
     for(int j : adj[i]){
        if(vist[j] == 0){
            helper(adj, j, p, vist, head);
        }
     }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1];
    for(int i = 1; i<=m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<int> head(n+1);
    vector<bool> vist(n+1, false);
    for(int i = 1; i <= n; i++){
        head[i] = i;
    }
    vector<int> ans;
    for(int i = 1; i<=n; i++){
        if(vist[i] == 0){
            helper(adj, i, i, vist, head);
            ans.push_back(i);
        }
    }
    
    cout << (ans.size()-1) << endl;
    for(int i = 1; i<ans.size(); i++){
        cout << ans[i-1] << " " << ans[i] << endl;
    }
    
    return 0;
}