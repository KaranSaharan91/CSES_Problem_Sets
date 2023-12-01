#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 1e5+1;

int par[maxN];
int ran[maxN];

int findp(int x){
    if(par[x] == x)return x;

    return (par[x] = findp(par[x]));
}

void join(int x, int y){
     
    if(ran[x] >= ran[y]){
        par[y] = x;
        ran[x] += ran[y];
    }
    else{
        par[x] = y;
        ran[y] += ran[x];
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    priority_queue<pair<ll, pair<int, int>> > q;

    for(int i = 1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        q.push({-c, {a, b}});
    } 

    for(int i = 1; i<=n; i++){
        par[i] = i;
        ran[i] = 1;
    }

    ll ans = 0;
   
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        int wt = t.first;
        int x = t.second.first;
        int y = t.second.second;

        int p1 = findp(x);
        int p2 = findp(y);
        
        if(p1 != p2){
            join(p1, p2);
            ans += wt;
        }
    }
    
    unordered_map<int, int> mp;
    
     for(int i = 1; i<=n; i++){
         int p = findp(i);
         if( i != 1 and mp.find(p) == mp.end()){
            cout << "IMPOSSIBLE" << endl;
            return 0;
         }
         mp[p] = 1;
     }

    cout << -ans << endl;
    return 0;
}