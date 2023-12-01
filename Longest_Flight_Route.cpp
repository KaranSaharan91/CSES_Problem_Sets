#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int> adj[], int i, vector<int> &city){
    if(i == city.size()-1){
        return 1;
    }
    if(city[i] != -1){
        return city[i];
    }
    int ans = 0;
    for(int j : adj[i]){
        int t = dfs(adj, j, city);
        ans = max(ans, t);
    }
    if(ans > 0){
        ans++;
    }
    city[i] = ans;
    return ans;
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

    vector<int> city(n+1, -1);
    int t = dfs(adj, 1, city);
    if(t == 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << city[1] << endl;
    city[n] = 1;
    int i = 1;
    cout << 1 << " ";
    while(i != n){
        int ans = 0;
        int j = -1;
        for(int v : adj[i]){
            if(ans < city[v]){
                ans = city[v];
                j = v;
            }
        }
        cout << j << " ";
        i = j;
    }
    cout << endl;

    return 0;

}