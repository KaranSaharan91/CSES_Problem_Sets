#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5;

bool vist[maxN];
int counter = 1;
string final_ans;
int n, v;

void dfs(string node, string ans){
   
    if(counter == v){
       string rel_ans = ans.substr(0, n);
       int x = -1;
       while(1){
           if(x == -1){
              x = n-1+n;
           }
           else{
              x = x+n;
           }
           rel_ans.push_back(ans[x]);
           if(x >= ans.size()-1)break;
       }
       final_ans = rel_ans;
       return;
    }

    for(int i = 0; i<2; i++){
        char ch = i+'0';
        string newNode = node.substr(1);
        newNode.push_back(ch);
        int NewNodeInt = stoi(newNode);
        if(vist[NewNodeInt])continue;
        vist[NewNodeInt] = true, counter++;
         string newans = ans+newNode;
         dfs(newNode, newans);
         if(!final_ans.empty())return;
         vist[NewNodeInt] = false;
         counter--;
    }
}

int power(int a, int b){
    int r = 1;
    while(b>0){
        if(b&1){
             r = r*a;
        }
        a = a*a;
        b = (b>>1);
    }
    return r;
}

void solve(){
    cin >> n;
    string ans;
    v = power(2, n);
    for(int i = 0; i<n; i++){
        ans.push_back('0');
    }
    vist[0] = true;
    dfs(ans, ans);
    cout << final_ans << endl;
}

int main(){
    
    solve();
    return 0;

}