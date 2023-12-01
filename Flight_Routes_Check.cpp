#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+1;

vector<int> ar1[maxN];
vector<int> ar2[maxN];

void dfs1(int src,  vector<bool> &vist){
     vist[src] = true;
     for(int j : ar1[src]){
        if(vist[j])continue;
        dfs1(j, vist);
     }
}

void dfs2(int src,  vector<bool> &vist){
     vist[src] = true;
     for(int j : ar2[src]){
        if(vist[j])continue;
        dfs2(j, vist);
     }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        ar1[a].push_back(b);
        ar2[b].push_back(a);
    }

    vector<bool> vist1(n+1, false);
    vector<bool> vist2(n+1, false);

    dfs1(1, vist1);
    dfs2(1, vist2);
    for(int i = 1; i<=n; i++){
        if(!vist1[i]){
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
         if(!vist2[i]){
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}