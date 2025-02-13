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
        int n, m, k; cin >> n >> m >> k;
        if(abs(n - m) > k || max(n, m) < k){
            cout << "-1\n";
            continue;
        }

        char last = '0';
        int len = n + m;
        if(max(n, m) == n){
            cout << string(k, '0');
            n -= k;
        } else {
            cout << string(k, '1');
            m -= k;
            last = '1';
        }

        for(int i = k; i < len; ++i){
            if(last == '0'){
                if(m){
                    cout << '1';
                    m--;
                    last = '1';
                } else {
                    cout << '0';
                    n--;
                    last = '0';
                }
            } else {
                if(n){
                    cout << '0';
                    n--;
                    last = '0';
                } else {
                    cout << '1';
                    m--;
                    last = '1';
                }
            }
        }

        cout << '\n';
    }
}
