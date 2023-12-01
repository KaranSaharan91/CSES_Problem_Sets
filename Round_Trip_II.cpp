#include<bits/stdc++.h>
using namespace std;

void topo(vector<int> adj[], int i, vector<bool> &vist, stack<int>&st){
     vist[i] = true;
     for(int j : adj[i]){
        if(!vist[j]){
            topo(adj, j, vist, st);
        }
     }
     st.push(i);
}

int dfs(vector<int> adj[], int i, vector<int> &v, vector<bool> &vist, stack<int>&ans){
    vist[i] = true;
    ans.push(i);
    for(int j : adj[i]){
       if(v[j] > 0){
          if(v[i]-v[j] >= 1){
            ans.push(j);
            return (v[i]-v[j]+2);
          }
       }
       else{
          v[j] = v[i]+1;
          int t = dfs(adj, j, v, vist, ans);
          v[j] = 0;
          if(t != -1)return t;
       }
    }
    ans.pop();
    return -1;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    stack<int> st;
    vector<bool> vist(n+1, false);

    for(int i = 1; i<=n; i++){
        if(!vist[i]){
            topo(adj, i, vist, st);
        }
    }

    for(int i = 1; i<=n; i++){
        vist[i] = false;
    }

    while(!st.empty()){
        int t = st.top();
        st.pop();
        if(vist[t])continue;
        stack<int> ans;
        vector<int> v(n+1, 0);
        v[t] = 1;
        int k = dfs(adj, t, v, vist, ans);
        if(k != -1){
            cout << k << endl;
            vector<int>cycle;
            while(k--){
                int val = ans.top();
                ans.pop();
                cycle.push_back(val);
            }
            reverse(cycle.begin(), cycle.end());
            for(int i : cycle){
                cout << i << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}