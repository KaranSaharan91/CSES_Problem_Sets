// #include<bits/stdc++.h>
// using namespace std;

// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};
// string D = "DURL";



// int main(){
//     int n, m;
//     cin >> n >> m;

//     vector<vector<char> > arr(n, vector<char>(m));

//     int a, b;

//     queue<pair<int, int>> q;

//     vector<vector<int> > dist(n, vector<int>(m, INT_MAX));

//     vector<vector<bool> > vist(n, vector<bool>(m, false)); 

//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             cin >> arr[i][j];
//             if(arr[i][j] == '#'){
//                 vist[i][j] = true;
//             }
//             if(arr[i][j] == 'A'){
//                 a = i;
//                 b = j;
//                 dist[i][j] = 0;
//                 vist[i][j] = true;
//             }
//             if(arr[i][j] == 'M'){
//                 vist[i][j] = true;
//                 dist[i][j] = 0;
//                 q.push({i, j});
//             }
//         }
//     }

//     while(!q.empty()){
//         auto t = q.front();
//         q.pop();
//         int x = t.first;
//         int y = t.second;
//         for(int i = 0; i<4; i++){
//         int nx = x+dx[i];
//         int ny = y+dy[i];
//         if(nx >= 0 and ny >= 0 and nx < arr.size() and ny < arr[0].size() and !vist[nx][ny]){
//                 dist[nx][ny] = dist[x][y]+1;
//                 vist[nx][ny] = true;
//                 q.push({nx, ny});
//         }
//        }
//     }

//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             if(arr[i][j] == '.'){
//                 vist[i][j] = false;
//             }
//         }
//     }

//     queue< pair< pair<int, int>, string> > q1;

//     q1.push({{a, b}, ""});

//     dist[a][b] = 0;

//     while(!q1.empty()){
//         auto t = q1.front();
//         q1.pop();
//         int x = t.first.first;
//         int y = t.first.second;

//         if(x == 0 || y == 0 || x == n-1 || y == m-1){
//              cout << "YES" << endl;
//              cout << t.second.size() << endl;
//              cout << t.second << endl;
//              return 0;
//         }

//         for(int i = 0; i<4; i++){
//         int nx = x+dx[i];
//         int ny = y+dy[i];
//         if(nx >= 0 and ny >= 0 and nx < n and ny < m and !vist[nx][ny] and dist[nx][ny] > dist[x][y]+1){
//                 vist[nx][ny] = true;
//                 dist[nx][ny] = dist[x][y]+1;
//                 q1.push({{nx, ny}, t.second+D[i]});
//         }
//         }
//     }
    
//     cout << "NO" << endl;

//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;
const int maxN = 1000;
const int INF = 0x3f3f3f3f;

int h[] = {1, -1, 0, 0};
int v[] = {0, 0, 1, -1};
struct point { int x, y; };

int N, M, sx, sy;
bool vis[maxN][maxN];
char ans[maxN*maxN], c[maxN][maxN], p[maxN][maxN];
int d1[maxN][maxN], d2[maxN][maxN];
queue<point> Q;

bool inbounds(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

void printsolution(int x, int y){
    int D = d2[x][y];
    printf("YES\n%d\n", D);
    for(int i = D-1; i >= 0; i--){
        ans[i] = p[x][y];
        if(ans[i] == 'D')       x--;
        else if(ans[i] == 'U')  x++;
        else if(ans[i] == 'R')  y--;
        else if(ans[i] == 'L')  y++;
    }
    for(int i = 0; i < D; i++)
        printf("%c", ans[i]);
    printf("\n");
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf(" %c", &c[i][j]);
            if(c[i][j] == '#')  vis[i][j] = true;
            else if(c[i][j] == 'M'){
                vis[i][j] = true;
                Q.push({i, j});
            } else if(c[i][j] == 'A'){
                sx = i; sy = j;
            }
        }
    }

    while(!Q.empty()){
        point P = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int x = P.x + h[i];
            int y = P.y + v[i];
            if(inbounds(x, y) && !vis[x][y]){
                d1[x][y] = d1[P.x][P.y] + 1;
                vis[x][y] = true;
                Q.push({x, y});
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!vis[i][j])  d1[i][j] = INF;
            vis[i][j] = (c[i][j] == '#');
        }
    }

    vis[sx][sy] = true;
    Q.push({sx, sy});
    while(!Q.empty()){
        point P = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int x = P.x + h[i];
            int y = P.y + v[i];
            if(inbounds(x, y) && !vis[x][y] && d2[P.x][P.y]+1 < d1[x][y]){
                if(i == 0)      p[x][y] = 'D';
                else if(i == 1) p[x][y] = 'U';
                else if(i == 2) p[x][y] = 'R';
                else if(i == 3) p[x][y] = 'L';
                d2[x][y] = d2[P.x][P.y] + 1;
                vis[x][y] = true;
                Q.push({x, y});
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(c[i][0] != '#' && c[i][0] != 'M' && vis[i][0]){
            printsolution(i, 0);
            return 0;
        } else if(c[i][M-1] != '#' && c[i][M-1] != 'M' && vis[i][M-1]){
            printsolution(i, M-1);
            return 0;
        }
    }

    for(int i = 0; i < M; i++){
        if(c[0][i] != '#' && c[0][i] != 'M' && vis[0][i]){
            printsolution(0, i);
            return 0;
        } else if(c[N-1][i] != '#' && c[N-1][i] != 'M' && vis[N-1][i]){
            printsolution(N-1, i);
            return 0;
        }
    }

    printf("NO\n");
}