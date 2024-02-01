/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int max1 = 0, max2 = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x > max1){
                max2 = max1;
                max1 = x;
            } else if(x > max2) max2 = x;
        }

        cout << (max1 - max2 <= 1 ? "YES\n" : "NO\n");
    }
}
