
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char st[4] = {'D', 'U', 'R', 'L'};

typedef array<int, 3> triple;




int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<char> > arr(n, vector<char>(m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    vector<vector<pair<int, char>>> dist(n, vector<pair<int, char>>(m, {INT_MAX, '\0'}));

    queue<triple> q;

    int bx, by;
    int ax, ay;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
           if(arr[i][j] == 'A'){
            ax = i;
            ay = j;
            q.push({0, i, j});
            dist[i][j].first = 0;
            dist[i][j].second = '\0';
           }
           if(arr[i][j] == 'B'){
            bx = i;
            by = j;
           }
        }
    }

    while(!q.empty()){
        auto t = q.front();
        q.pop();

        // cout << t[1] << " " << t[2] << endl;

        if(arr[t[1]][t[2]] == 'B')continue;
        
        for(int i = 0; i<4; i++){
            int nx = t[1]+dx[i];
            int ny = t[2]+dy[i];

            if(nx < 0 or ny < 0 or nx >= n or ny >= m or arr[nx][ny] == '#')continue;
            
            if(dist[nx][ny].first > t[0]+1){
                dist[nx][ny].first = t[0]+1;
                dist[nx][ny].second = st[i];
                q.push({t[0]+1, nx, ny});
            }
        }
    }

    if(dist[bx][by].first == INT_MAX){
        cout << "NO" << endl;
    }

    else{
        cout << "YES" << endl;
        cout << dist[bx][by].first << endl;
        string ans = "";
        int i = bx;
        int j = by;
        int t = dist[bx][by].first;
        while(t){
            ans.push_back(dist[i][j].second);
            t--;
            if(dist[i][j].second == 'D'){
                i--;
            }
            else if(dist[i][j].second == 'U'){
                i++;
            }
            else if(dist[i][j].second == 'R'){
                j--;
            }
            else if(dist[i][j].second == 'L'){
                j++;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }

    

    return 0;
}