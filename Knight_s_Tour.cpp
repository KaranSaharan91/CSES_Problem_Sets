#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
int dy[8] = {-1, 1, -1, 1, -2, 2, -2, 2};

pair<bool, vector<vector<int>>> helper(int x, int y, int m1, int m2, vector<vector<int>> vist, map<pair<int, int>, bool> &mp){
            if(vist[x][y] == 64){
                return {true, vist};
            }
            if(mp.find({m1, m2}) != mp.end())return {false, {{}}};

            for(int i = 0; i<8; i++){
                vector<vector<int>> temp = vist;
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx >= 0 and ny >= 0 and nx<8 and ny < 8 and temp[nx][ny] == 0){
                   temp[nx][ny] = 1+temp[x][y];
                   int p1 = (m1 | (1<<nx));
                   int p2 = (m2 | (1<<ny));
                   pair<bool, vector<vector<int>>> t =  helper(nx, ny, p1, p2, temp, mp);
                   if(t.first)return t;
                }
            }
            mp[{m1, m2}] = false;
            return {false, {{}}};
}


int main(){
    int x, y;
    cin >> x >> y;

    vector<vector<int>> vist(8, vector<int>(8, 0));
    x--;
    y--;
    vist[y][x] = 1;

    map<pair<int, int>, bool> mp;

    pair<bool, vector<vector<int>>> ans = helper(y, x, (1<<y), (1<<x), vist, mp);
    vector<vector<int>> temp = ans.second;

    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}