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
    int n, m; cin >> n >> m;
    int64_t g = 0, ant, first;
    cin >> ant; first = ant;
    for(int i = 1; i < n; ++i){
        int64_t x; cin >> x;
        g = gcd(g, x - ant);
        ant = x;
    }

    for(int i = 1; i <= m; ++i){
        int64_t x; cin >> x;
        if(g % x == 0){
            cout << "YES\n" << first << ' ' << i << '\n';
            return 0;
        }
    }
    cout << "NO\n";
}
