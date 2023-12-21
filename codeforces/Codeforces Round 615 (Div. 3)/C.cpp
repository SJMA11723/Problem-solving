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
        unordered_map<int, int> primes;
        int tmp = n, a, b, c = b = a = 0;
        for(int i = 2; i * i <= tmp; ++i){
            while(tmp % i == 0){
                primes[i]++;
                tmp /= i;
            }
        }
        if(tmp > 1) primes[tmp]++;

        for(auto &it : primes){
            if(b) break;
            if(!a){
                a = it.first;
                if(it.second >= 3) b = a * a;
            } else if(!b) b = it.first;
        }
        if(a && b && n / a / b != a && n / a / b != b && n / a / b > 1) c = n / a / b;

        if(a && b && c) cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
        else cout << "NO\n";
    }
}
