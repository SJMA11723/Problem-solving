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
        int tmp = n;
        vector<pair<int, int>> primes;
        for(int i = 2; i * i <= tmp; ++i){
            if(tmp % i) continue;
            int cnt = 0;
            while(tmp % i == 0){
                cnt++;
                tmp /= i;
            }
            primes.push_back({i, cnt});
        }
        if(tmp > 1) primes.push_back({tmp, 1});

        int a = -1, b = -1, c = -1;
        if(primes.size() > 2){
            a = primes[0].first;
            b = primes[1].first;
            c = n / a / b;
        } else if(primes.size() == 1){
            a = primes[0].first;
            b = a * a;
            c = n / a / b;
        } else {
            a = primes[0].first;
            if(primes[0].second >= 3) b = a * a;
            else b = primes[1].first;
            c = n / a / b;
        }

        if(a * b * c != n || a == b || a == c || b == c || c < 2) cout << "NO\n";
        else cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
    }
}
