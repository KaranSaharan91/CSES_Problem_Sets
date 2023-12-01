#include<bits/stdc++.h>
using namespace std;

bool helper(vector<int> adj[], int x, vector<int> &ans){
     if(ans[x] == 0){
        ans[x] = 1;
     }
     
     for(int j : adj[x]){
         if(ans[j] != 0 and ans[j] == ans[x])return false;
         if(ans[j] == 0){
            if(ans[x] == 1){
                ans[j] = 2;
            }
            else{
                ans[j] = 1;
            }
            bool t = helper(adj, j, ans);
            if(!t)return false;
         }
     }

     return true;
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

    vector<int> ans(n+1, 0);
    int f = 1;

    for(int i = 1; i<=n; i++){
        bool t = helper(adj, i, ans);
        if(!t){
             f = 0;
             cout << "IMPOSSIBLE" << endl;
             break;
        }
    }
    

    if(f == 1){
        for(int i = 1; i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}