/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n; cin >> n;
    int64_t fib = 2, prv = 1;
    int ans = 0;
    while(fib <= n){
        ans++;
        int64_t tmp = fib;
        fib += prv;
        prv = tmp;
    }
    cout << ans << '\n';
}
