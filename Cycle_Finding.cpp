 #include<bits/stdc++.h>
 using namespace std;
 #define ll long long


 int main(){
     int n, m;
     cin >> n >> m;
     vector<pair<pair<int, int>, ll>> E;
     
     for(int i= 0; i<m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        E.push_back({{u, v}, w});
     }

     vector<ll> dist(n+1, 0);
     vector<int> rel(n+1, -1);
     int flag = 0;
     int x = -1;

     for(int i = 1; i<=n; i++){
         flag = 0;
         for(auto j : E){
            if(dist[j.first.second] > dist[j.first.first]+j.second){
                dist[j.first.second] = dist[j.first.first]+j.second;
                rel[j.first.second] = j.first.first;
                flag = 1;
                x = j.first.second;
            }
         }
     }

     if(flag == 0){
        cout << "NO" << endl;
     }

     else{
        cout << "YES" << endl;
        for(int i = 1; i<=n; i++){
            x = rel[x];
        }

        vector<int> cycle;
        for(int i = x; ;i = rel[i]){
            cycle.push_back(i);
            if(i == x and cycle.size() > 1)break;
        }
        reverse(cycle.begin(), cycle.end());
        for(int j : cycle){
            cout << j << " ";
        }
        
        cout << endl;
     }
 
     return 0;
 }