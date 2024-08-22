/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    map<int, int> cub;
    int primes_x[n];
    for(int &x : primes_x) cin >> x;
    for(int i = 0; i < n; ++i){
        int e; cin >> e;
        cub[primes_x[i]] = e;
    }

    int m; cin >> m;
    int primes_y[m], ans = 1;
    for(int &x : primes_y) cin >> x;
    for(int i = 0; i < m; ++i){
        int e; cin >> e;
        if(!cub.count(primes_y[i]) || cub[primes_y[i]] < e) ans = 0;
        else if(cub[primes_y[i]] == e) cub.erase(primes_y[i]);
    }

    for(int i = 0; i < cub.size(); ++i){
        ans += ans;
        if(ans >= MOD) ans -= MOD;
    }

    cout << ans << '\n';
}
