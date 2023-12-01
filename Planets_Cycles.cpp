#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5+1;

// int v[maxN];
// int freq[maxN];
// int arr[maxN];
// int root[maxN];
// int up[maxN][20];
// int dfs(int src, int k){
//     v[src] = k;

//     int d = arr[src];

//     if(v[d] > 0 and freq[d] > 0){
//        freq[src] = 1+freq[d];
//        return 0;
//     }

//     if(v[d] > 0){
//         int f = v[src]-v[d]+1;
//         freq[src] = f;
//         return (f-1);
//     }

//     int t = dfs(arr[src], k+1);

//     if(t > 0){
//         freq[src] = freq[arr[src]];
//         return (t-1);
//     }

//     freq[src] = 1+freq[arr[src]];
//     return t;
// }

// int main(){
//     int n;
//     cin >> n;

//     for(int i = 1; i<=n; i++){
//         cin >> arr[i];
//     }

//     for(int i = 1; i<=n; i++){
//         if(v[i] > 0)continue;
//         int t = dfs(i, 1);
//     }

//     for(int i = 1; i<=n; i++){
//          cout << freq[i] << " "; 
//     }
//     cout << endl;
//     return 0;
// }

int v[maxN];
int freq[maxN];
int arr[maxN];
int root[maxN];
int up[maxN][20];

int dfs(int arr[], int src, int dist){
    v[src] = dist;

    int d = arr[src];

    if(freq[d] > 0){
        // up[src][0] = d;
        // root[src] = d;
        freq[src] = 1+freq[d];
        return 0;
    }

    if(v[d] > 0){
        int f = v[src]-v[d]+1;
        freq[src] = f;
        // root[src] = src;
        return (f-1);
    }
    int t = dfs(arr, d, dist+1);
    
    if(t > 0){
        freq[src] = freq[d];
        // root[src] = src;
        return t-1;
    }
    // root[src] = d;
    freq[src] = 1+freq[d];
    return 0;
}


int main(){
    int n;
    cin >> n;

    for(int i = 1; i<=n; i++)cin >> arr[i];

    for(int i = 1; i<=n; i++){
    if(v[i] > 0)continue;
    int t = dfs(arr, i, 1);
    }

    for(int i = 1; i<=n; i++){
        cout << freq[i] << " ";
    }
    return 0;
}