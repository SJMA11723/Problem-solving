/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int l = 2, r = 999;
        while(l < r){
            int mid = l + (r - l) / 2;
            cout << "? 1 " << mid << endl;
            int res; cin >> res;
            if(res == mid) l = mid + 1;
            else r = mid;
        }
        cout << "! " << l << endl;
    }
}
