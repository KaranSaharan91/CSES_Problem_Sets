#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 1e5+1;

void dfs(vector<int> adj[], int src, vector<bool> &vist, stack<int> &st){
     vist[src] = true;
     for(int i : adj[src]){
        if(vist[i])continue;
        dfs(adj, i, vist, st);
     }
     st.push(src);
}

void helper(vector<int> adj[], int src, vector<int> &v, vector<bool> &vist){
   v.push_back(src);
   vist[src] = true;
   for(int i : adj[src]){
    if(vist[i])continue;
    helper(adj, i, v, vist);
   }
   vist[src] = true;
}

vector<int> node[maxN];
void dfs2(vector<int> adj[], vector<int> &val, int src, vector<bool> &vist){
     vist[src] = true;
     for(int i : adj[src]){
        if(val[src] != val[i]){
            node[val[src]].push_back(val[i]);
        }
        if(vist[i])continue;
        dfs2(adj, val, i, vist);
     }
}

void dfs3(int src, stack<int>&st, vector<bool> &vist){
    vist[src] = true;
    for(int i : node[src]){
        if(vist[i])continue;
        dfs3(i, st, vist);
    }
    st.push(src);
}

ll helper1(int src, map<int, ll> &mp, vector<ll> &dist){
    if(dist[src] != -1)return dist[src];
    ll sum = -1;
    for(int i : node[src]){
        ll t = helper1(i, mp, dist);
        if(t > sum) sum = t;
    }
    dist[src] = mp[src];
    if(sum != -1)dist[src] += sum;
    return dist[src];
}


int main(){
    int n, m; 
    cin >> n >> m;

    vector<ll> arr(n+1);
    for(int i = 1; i<= n; i++) cin >> arr[i];

    vector<int> adj[n+1];
    vector<int> badj[n+1];
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        badj[b].push_back(a);
    }

    stack<int> st;
    vector<bool> vist(n+1, false);

    for(int i = 1; i<=n; i++){
        if(vist[i])continue;
        dfs(adj, i, vist, st); 
    }

    vector<int> val(n+1);

    int k = 1;

    vector<bool> v(n+1, false);

    map<int, ll> mp;

    while(!st.empty()){
        int t = st.top();
        st.pop();
        if(v[t])continue;
        vector<int> ans;
        helper(badj, t, ans, v);
        ll sum = 0;
        for(int i : ans){
            sum += arr[i];
        }
        for(int i : ans){
            val[i] = k;
        }
        mp[k] = sum;
        k++;
    }

    vector<bool> v1(n+1, false);

    for(int i = 1; i<=n; i++){
        if(v1[i])continue;
        dfs2(adj, val, i, v1);
    }
    

    vector<bool> v2(n+1, false);

    for(int i = 1; i<k; i++){
       if(v2[i])continue;
       dfs3(i, st, v2);
    }

    vector<ll> dist(k, -1);
    ll sum1 = -1;
    while(!st.empty()){
        int t = st.top();
        st.pop();
        ll temp = helper1(t, mp, dist);
        if(temp > sum1)sum1 = temp;
    }

    cout << sum1 << endl;

    return 0;
}