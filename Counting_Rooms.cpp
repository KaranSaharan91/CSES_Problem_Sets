#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<char> >& arr, int x, int y, vector<vector<int> >& vist){
     vist[x][y] = 1;
     int dx[4] = {1, -1, 0, 0};
     int dy[4] = {0, 0, 1, -1};
    
     
     for(int i = 0; i<4; i++){
         int nx = x+dx[i];
         int ny = y+dy[i];
         if(nx >= 0 and ny >= 0 and nx<arr.size() and ny<arr[0].size() and vist[nx][ny] == 0 and arr[nx][ny] == '.'){
            helper(arr, nx, ny, vist);
         }
     }
}

int main() {
    // Write C++ code here
    int n, m;
    cin >> n >> m;

    vector<vector<char> > arr(n, vector<char>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int> > vist(n, vector<int>(m, 0));
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(vist[i][j] == 0 and arr[i][j] == '.'){
                helper(arr, i, j, vist);
                ans++;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}