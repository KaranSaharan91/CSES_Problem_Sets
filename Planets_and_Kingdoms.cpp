#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;

vector<int> ar[maxN];
vector<int> ar2[maxN];

bool vist[maxN];
int king[maxN];
vector<int> ord;


void topo(int src, stack<int> &st){
     vist[src] = true;
     for(int j : ar[src]){
        if(vist[j])continue;
        topo(j, st);
     }
     st.push(src);
}

void dfs(int src){
     vist[src] = true;
     ord.push_back(src);
     for(int j : ar2[src]){
        if(vist[j])continue;
        dfs(j);
     }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar2[b].push_back(a);
    }

    stack<int> st;

    for(int i = 1; i<=n; i++){
        if(vist[i])continue;
        topo(i, st);
        king[i] = 0;
    }

    for(int i = 1; i<=n; i++){
        vist[i] = false;
    }
    
    int k = 0;

    while(!st.empty()){
        int t = st.top();
        st.pop();
       
        if(!vist[t]){
            dfs(t);
            k++;
            for(int i : ord){
                king[i] = k;
            }
            ord.clear();
        }
    }

    cout << k << endl;

    for(int i = 1; i<=n; i++){
        cout << king[i] << " ";
    }
    cout << endl;
    return 0;
}
