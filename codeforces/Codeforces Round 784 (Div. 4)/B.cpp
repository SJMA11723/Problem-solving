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
        int cub[n + 1] = {};
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cub[x]++;
        }
        bool ok = false;
        for(int i = 0; i <= n; ++i){
            if(cub[i] >= 3){
                cout << i << '\n';
                ok = true;
                break;
            }
        }
        if(!ok) cout << "-1\n";
    }
}
