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
        int cnt = 0, cnt_ok = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(x % 2) cnt--;
            else cnt++;
            if(x % 2 == i % 2) cnt_ok++;
        }

        if(n - n / 2 * 2 != cnt) cout << "-1\n";
        else cout << (n - cnt_ok) / 2 << '\n';
    }
}

