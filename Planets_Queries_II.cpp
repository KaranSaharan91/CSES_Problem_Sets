#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5+1;
int root[maxN];
int up[maxN][31];
int cycle_id[maxN];
int lavel[maxN];
int freq[maxN];
int arr[maxN];
int v[maxN];
bool vist[maxN];
int id = 1;

int dfs(int src, int dist){
    vist[src] = true;
    v[src] = dist;

    int d = arr[src];

    if(v[d] > 0){
       root[src] = src;
       int f = v[src]-v[d]+1;
       freq[src] = f;
       cycle_id[src] = id;
       lavel[src] = v[src];
       v[src] = 0; 
       return (f-1);
    }

    if(vist[d]){
        root[src] = root[d];
        lavel[src] = 1+lavel[d];
        cycle_id[src] = cycle_id[d];
        up[src][0] = d;
        for(int i = 1; i<31; i++){
            if(up[src][i-1]){
                up[src][i] = up[up[src][i-1]][i-1];
            }
            else break;
        }
        v[src] = 0;
        return 0;
    }

    int t = dfs(d, dist+1);

    if(t > 0){
        freq[src] = freq[d];
        cycle_id[src] = id;
        lavel[src] = dist;
        root[src] = src;
        v[src] = 0;
        return t-1;
    }
    
    root[src] = root[d];
    lavel[src] = 1+lavel[d];
    cycle_id[src] = cycle_id[d];
    up[src][0] = d;
    for(int i = 1; i<31; i++){
        if(up[src][i-1]){
             up[src][i] = up[up[src][i-1]][i-1];
        }
        else break;
    }
    v[src] = 0;
    return 0;
}

int lca(int a, int b){
    int k = lavel[a]-lavel[b];
    int dist = 0;
    for(int i = 30; i>=0; i--){
        if(1&(k >> i)){
            a = up[a][i];
            dist += (1<<i);
        }
    }
    return a == b ? dist : -1;
}

int main(){
    int n, q;
    cin >> n >> q;

    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i<=n; i++){
        if(vist[i])continue;
        int t = dfs(i, 1);
        id++;
    }

    while(q--){
        int a, b;
        cin >> a >> b;

        if(cycle_id[a] != cycle_id[b]){
            cout << -1 << endl;
            continue;
        }

        if(root[a] == root[b]){
            if(lavel[a] < lavel[b]){
                cout << -1 << endl;
                continue;
            }
            int dist = lca(a, b);
            cout << dist << endl;
            continue;
        }
        if(b != root[b]){
            cout << -1 << endl;
            continue;
        }
        
        int diff = lavel[a]-lavel[root[a]];
        a = root[a];
        int dist = lavel[b]-lavel[a];
        if(dist < 0){
            dist = dist+freq[b];
        }
        cout << diff+dist << endl;
        continue;
    }
    
    return 0;
}

