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
    int64_t x; cin >> x;
    int64_t a = LLONG_MAX, b;
    for(int64_t d = 1; d * d <= x; ++d){
        if(x % d || gcd(d, x / d) > 1) continue;

        if(max(d, x / d) < max(a, b)){
            a = d;
            b = x / d;
        }
    }
    cout << a << ' ' << b << '\n';
}
