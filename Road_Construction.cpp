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

    for(int i = 1; i<=n; i++){
        par[i] = i;
        ran[i] = 1;
    }

    int comp = n;
    int mr = 1;

    for(int i = 1; i<=m; i++){
        int a, b;

        cin >> a >> b;

        int p1 = findp(a);
        int p2 = findp(b);

        if(p1 != p2){
            join(p1, p2);
            mr = max(mr, max(ran[p1], ran[p2]));
            comp--;
        }
         cout << comp << " " << mr << endl;

    } 

    
    return 0;
}