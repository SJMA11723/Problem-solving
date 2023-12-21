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
        long long n; cin >> n;
        int a, b;
        int tmp = n;
        long long lcm = LLONG_MAX;
        for(long long i = 2; i * i <= tmp; ++i){
            if(tmp % i) continue;
            if(n / i * (i - 1) < lcm){
                lcm = n / i * (i - 1);
                a = n / i;
                b = n / i * (i - 1);
            }
            while(tmp % i == 0) tmp /= i;
        }
        if(tmp > 1 && n / tmp * (tmp - 1) < lcm){
            a = n / tmp;
            b = n / tmp * (tmp - 1);
        }
        cout << a << ' ' << b << '\n';
    }
}
