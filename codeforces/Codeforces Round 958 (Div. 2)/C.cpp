/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int64_t n; cin >> n;
        if(__builtin_popcountll(n) == 1){
            cout << "1\n" << n << '\n';
            continue;
        }
        cout << __builtin_popcountll(n) + 1 << '\n';
        for(int k = 62; 0 <= k; --k)
            if(is_on(n, k)) cout << (n ^ (1ll << k)) << ' ';
        cout << n << '\n';
    }
}
