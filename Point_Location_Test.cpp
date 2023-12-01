#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        
        if(x2 == x1){
           if(x1 == x3){
            cout << "TOUCH" << endl;
            continue;
           }

           if(x3 > x1){
            if(y1 < y2){
                cout << "RIGHT" << endl;
                continue; 
            }
            else{
                cout << "LEFT" << endl;
                continue;
            }
           }

           else{
             if(y1 < y2){
                cout << "LEFT" << endl;
                continue;
             }
             else{
                cout << "RIGHT" << endl;
                continue;
             }
           }
        }

        double m = (y2-y1)/(x2-x1);
        
        double c = y1-m*x1;

        double val = y3-m*x3-c;

        if(val == 0.0){
            cout << "TOUCH" << endl;
            continue;
        }

        if(val > 0.0){
            if(x1 > x2){
                cout << "RIGHT" << endl;
                continue;
            }
            else{
                cout << "LEFT" << endl;
                continue; 
            }
        }

        else{
            if(x1 > x2){
                cout << "LEFT" << endl;
                continue;
            }
            else{
                cout << "RIGHT" << endl;
                continue; 
            }
        }
    }

    return 0;
}