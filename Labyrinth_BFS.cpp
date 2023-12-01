
#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int n, m;
vector<vector<char> > arr(N, vector<char>(N));
vector<vector<bool> > vist(N, vector<bool>(N, false));
string path;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string D = "DURL";

int main() {
    // Write C++ code here
   
    cin >> n >> m;
    int x, y;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'A'){
                x = i;
                y = j;
            }
        }
    }

    int ans = 0;
    
    queue<pair<int, int>> q;
    unordered_map<pair<int, int>, string> mp;

    q.push({x, y});

    while(!q.empty()){
        auto f = q.front();
        q.pop();
        int x1 = f.first;
        int y1 = f.second;
        if(arr[x1][y1] == 'B'){
            if(path.size() == 0 || path.size() > mp[{x1, y1}].size()){
               ans = 1;
               path = mp[{x1, y1}];
            }
        }
        for(int i  = 0; i<4; i++){
            int nx = x1+dx[i];
            int ny = y1+dy[i];
            if(nx<n and ny<m and nx>=0 and ny>=0 and arr[nx][ny] != '#'){
                if(mp.find({nx, ny}) != mp.end() and mp[{nx, ny}] <= (mp[{x1, y1}]+D[i]))continue;
                mp[{nx, ny}] = mp[{x1, y1}]+D[i];
                q.push({nx, ny});
            }
        }
    }

    if(ans == 1){
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
    return 0;
}