/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

bool is_prime(int x){
    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0) return false;
    return x > 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vi primes;
    int curp = 2;
    while(sz(primes) < 1e4){
        if(is_prime(curp)) primes.pb(curp);
        curp++;
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << "2 ";
        for(int i = 1; i < n; ++i) cout << 1ll * primes[i] * primes[i - 1] << " \n"[i == n];
    }
}
