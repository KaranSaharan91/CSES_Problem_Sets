#include<bits/stdc++.h>
using namespace std;

long orin(long x1, long y1, long x2, long y2, long x3, long y3){
     long val = (x3-x2)*(y2-y1) - (x2-x1)*(y3-y2);
     if(val>0)return 1;
     if(val<0)return 2;
     return 0;
}

bool onseg(long x1, long y1, long x2, long y2, long x3, long y3){
    if(max(x1, x2) >= x3 and min(x1, x3) <= x3 and max(y1, y2) >= y3 and min(y1, y2) <= y3){
        return true;
    }
     return false;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        long x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        
        long o1 = orin(x1, y1, x2, y2, x3, y3);
        long o2 = orin(x1, y1, x2, y2, x4, y4);
        long o3 = orin(x3, y3, x4, y4, x1, y1);
        long o4 = orin(x3, y3, x4, y4, x2, y2);

        if((o1 != o2) and (o3 != o4)){
            cout << "YES" << endl;
            continue;
        }

        if(o1 == 0 and onseg(x1, y1, x2, y2, x3, y3)){
            cout << "YES" << endl;
            continue;
        }

        if(o2 == 0 and onseg(x3, y3, x4, y4, x1, y1)){
            cout << "YES" << endl;
            continue;
        }

        if(o3 == 0 and onseg(x3, y3, x4, y4, x2, y2)){
            cout << "YES" << endl;
            continue;
        }

        if(o4 == 0 and onseg(x1, y1, x2, y2, x4, y4)){
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }

    return 0;
}

