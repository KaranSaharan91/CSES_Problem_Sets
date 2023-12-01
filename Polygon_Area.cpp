#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;

    vector<pair<long, long>> a;

    for(int i = 0; i<n; i++){
        long x, y;
        cin >> x >> y;
        a.push_back({x, y});
    } 

    long ans = 0;

    for(int i = 0; i<n; i++){
        int j;
        if(i == n-1){
            j = 0;
        }
        else{
            j = i+1;
        }
         long x1 = a[i].first;
         long y1 = a[i].second;
         long x2 = a[j].first;
         long y2 = a[j].second;


         ans += ((x1*y2)-(y1*x2));
         
    }

    cout << abs(ans) << endl;

    return 0;
}