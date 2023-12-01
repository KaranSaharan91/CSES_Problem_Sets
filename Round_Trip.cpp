#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> adj[], int src, int pr, int d, vector<int> &v, stack<int> &ans){
    v[src] = d;
    for(int i : adj[src]){
        if(i == pr)continue;
        if(v[i] >= 0){
            int num = d-v[i]+1;
            if(num >= 3){
                ans.push(i);
                ans.push(src);
                return num-1;
            }
            else continue;
        }
        
        int t = helper(adj, i, src, d+1, v, ans);

        if(t > 0){
            ans.push(src);
            return t-1;
        }
        if(t == 0){
            return 0;
        }
    }
    return -1;
}


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

    vector<int> vist(n+1, -1);
    stack<int> ans;

    int t = -1;

    for(int i = 1; i<=n; i++){
     if(vist[i] >= 0)continue;
     t = helper(adj, i, 0, 0, vist, ans);
     if(t != -1)break;
    }

    if(t == -1){
        cout << "IMPOSSIBLE" << endl;
    }
    
    else{
        cout << ans.size() << endl;
        while(!ans.empty()){
            cout << ans.top() << " ";
            ans.pop();
        }
    }

    return 0;
}