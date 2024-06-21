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
        int P[n];
        for(int i = 0; i < n; ++i){
            cin >> P[i];
            P[i]--;
        }

        int ans = 3;
        for(int i = 0; i < n; ++i){
            if(i == P[P[i]]){
                ans = 2;
                break;
            }
        }
        cout << ans << '\n';
    }
}
