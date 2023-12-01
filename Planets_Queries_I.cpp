#include<bits/stdc++.h>
using namespace std;

const int maxN = 2e5+1;
int up[maxN][31];
int freq[maxN];
int v[maxN];
int arr[maxN];

int main(){
    int n, q;
    cin >> n >> q;

    for(int i = 1; i<=n; i++){
        cin >> arr[i];
        cin >> up[i][0];
    }

    for(int i = 1; i<31; i++){
        for(int j = 1; j<=n; j++){
            up[j][i] = up[up[j][i-1]][i-1];
        }
    }
   
    while(q--){
        int x, k;
        cin >> x >> k;
        for(int i = 0; i<31; i++){
            if((k&(1<<i))){
                x = up[x][i];
            }
        }
        cout << x << endl;
    }
    return 0;


}
// #include <bits/stdc++.h>

// using namespace std;
// const int maxN = 2e5+1;
// const int logK = 31;

// int N, Q, x, k, p[maxN][logK];

// int main(){
//     scanf("%d %d", &N, &Q);
//     for(int i = 1; i <= N; i++)
//         scanf("%d", &p[i][0]);
//     for(int j = 1; j < logK; j++)
//         for(int i = 1; i <= N; i++)
//             p[i][j] = p[p[i][j-1]][j-1];

//     for(int q = 0; q < Q; q++){
//         scanf("%d %d", &x, &k);
//         for(int i = 0; i < logK; i++)
//             if(k&(1<<i))
//                 x = p[x][i];
//         printf("%d\n", x);
//     }
// }