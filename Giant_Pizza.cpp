#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    for(int i = 0; i<n; i++){
        string a, b, c, d;
        cin >> a >> b >> c >> d;

        if(a == "+"){
            string st = "+"+b;
            mp[st]++;
        }
        else{
            string st = "-"+b;
            mp[st]++;
        }

        if(c == "+"){
            string st = "+"+d;
            mp[st]++;
        }
        else{
            string st = "-"+d;
            mp[st]++;
        }
    }

    for(int i = 1; i<=m; i++){
        string st = "+"+to_string(i);
        if(mp.find(st) != mp.end()){
            cout << '+' << " ";
        }
        else{
            cout << '-' << " ";
        }
    }


    return 0;
}