#include<bits/stdc++.h>
using namespace std;

int orin(long x1, long y1, long x2, long y2, long x3, long y3){
    long val = (x3-x2)*(y2-y1)-(x2-x1)*(y3-y2);
    if(val == 0)return 0;
    if(val<0)return 1;
    if(val>0)return 2;
}

bool segm(long x1, long y1, long x2, long y2, long x3, long y3){
     if(max(x1, x2) >= x3 and min(x1, x2) <= x3 and max(y1, y2) >= y3 and min(y1, y2) <= y3){
        return true;
     }
     return false;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<long, long>> v;

    for(int i = 0; i<n; i++){
        long x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    
    for(int i = 0; i<m; i++){
        long x3, y3;
        cin >> x3 >> y3;
        long x4 = INT_MAX;
        long y4 = INT_MAX+1;
        int cnt = 0;
        int f = 0;
        for(int j = 0; j<n; j++){
            long x1 = v[j].first;
            long y1 = v[j].second;
            long x2, y2;
            if(j==n-1){
               x2 = v[0].first;
               y2 = v[0].second;
            }
            else{
                x2 = v[j+1].first;
                y2 = v[j+1].second;
            }
            
            int o1 = orin(x1, y1, x2, y2, x3, y3);
            int o2 = orin(x1, y1, x2, y2, x4, y4);
            int o3 = orin(x3, y3, x4, y4, x1, y1);
            int o4 = orin(x3, y3, x4, y4, x2, y2);

            if(o1 == 0 and segm(x1, y1, x2, y2, x3, y3)){
                f = 1;
                break;
            }
            if(o1 != o2 and o3 != o4){
                cnt++;
                continue;
            }
        }
        if(f == 1){
            cout << "BOUNDARY" << endl;
            continue;
        }

        if(cnt%2 != 0){
            cout << "INSIDE" << endl;
        }
        else{
            cout << "OUTSIDE" << endl;
        }
    }

    return 0;
}