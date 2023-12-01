#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> &ans, int x){
    int s = 0;
    int e = ans.size()-1;
    int j = -1;
    while(s <= e){
        int mid = s+(e-s)/2;
        if(ans[mid] >= x){
            j = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return j;
}

int main(){

    int n;

    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i = 1; i<n; i++){
       if(ans[ans.size()-1] < arr[i]){
        ans.push_back(arr[i]);
        continue;
       }

       int j = helper(ans, arr[i]);
       ans[j] = arr[i];
    }

    cout << ans.size() << endl;

    return 0;

}
