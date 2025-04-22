/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))
#define MAXSQRT 10000000

using namespace std;

vector<int> primes;
vector<pair<int64_t, int>> divisors;

void generate_divisors(int idx = 0, int cnt_primes = 1, int64_t mlcm = 1){
    for(int i = idx; i < primes.size() && mlcm * primes[i] <= MAXSQRT; ++i){
        mlcm *= primes[i];
        divisors.push_back({mlcm * mlcm, cnt_primes});
        generate_divisors(i + 1, cnt_primes + 1, mlcm);
        mlcm /= primes[i];
    }
}

void criba(int n){
    primes.clear();
    if(n < 2) return;

    vector<bool> no_primo(n + 1);
    no_primo[0] = no_primo[1] = true;

    for(long long i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(long long j = i * i; j <= n; j += 2 * i)
            no_primo[j] = true;
    }

    primes.push_back(2);
    for(int i = 3; i <= n; i += 2){
        if(!no_primo[i])
            primes.push_back(i);
    }
}

unordered_map<int64_t, int64_t> memo;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    criba(MAXSQRT);
    generate_divisors();

    sort(divisors.begin(), divisors.end());

    int t; cin >> t;
    while(t--){
        int64_t n; cin >> n;
        int64_t ans = n;
        if(memo.count(n)) cout << memo[n] << '\n';
        else {
            for(pair<int64_t, int> p : divisors)
            if(p.first <= n) ans += n / p.first * ((p.second & 1) ? -1 : 1);
            else break;
            cout << (memo[n] = ans) << '\n';
        }
    }
}
