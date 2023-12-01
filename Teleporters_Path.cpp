#include<bits/stdc++.h>
using namespace std;

// final _ans
const int maxN = 1e5+1;

int N, M, in[maxN];
bool vis[maxN];
vector<int> adj[maxN], tour;
stack<int> S;

void dfs(int u = 1, int p = -1){
    vis[u] = true;
    for(int i : adj[u]){
        if(vis[i])continue;
        dfs(i, u);
    }
}

int main(){
    cin >> N >> M;

    for(int i = 0; i<M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }

    dfs();

    bool exist = vis[N];

    exist &= (in[1]+1 == (int)adj[1].size());
    exist &= (in[N]-1 == (int)adj[N].size());

    for(int i = 2; i<N; i++){
        exist &= (in[i] == (int)adj[i].size());
        if(!vis[i]) exist &= (in[i] == 0 and adj[i].size() == 0);
    }

    if(!exist){
        cout << "IMPOSSIBLE" << endl;
    }

    else{
        S.push(1);

        while(!S.empty()){
            int t = S.top();
            if(!adj[t].empty()){
                int v = adj[t].back();
                adj[t].pop_back();
                S.push(v);
            }
            else{
                tour.push_back(t);
                S.pop();
            }
        }

        reverse(tour.begin(), tour.end());

        for(int i : tour){
            cout << i << " ";
        }

        cout << endl;
    }

    return 0;
}