#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef uint64_t ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

ull modpow(ull b, ull e, ull mod){
    ull ans = 1;
    b %= mod;
    for(; e; b = b * b % mod, e /= 2)
        if(e & 1) ans = ans * b % mod;
    return ans;
}

#define MAXN 70000000
int ans[MAXN + 1];

void criba(int n, vi &primos){
    primos.clear();
    if(n < 2) return;
    vector<bool> no_primo(n + 1);
    no_primo[0] = no_primo[1] = true;
    for(ll i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(ll j = i * i; j <= n; j += 2 * i)
            no_primo[j] = true;
    }

    primos.pb(2);
    for(int i = 3; i <= n; i += 2)
        if(!no_primo[i]) primos.pb(i);
}

vi primos;
bitset<MAXN + 1> comp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //auto ini = chrono::high_resolution_clock::now();
    
    criba(MAXN, primos);

    for(int p : primos){
        if(p % 4 != 1) continue;
        ull r = 0;

        for(ull a = 2; a < p; ++a){
            if(modpow(a, (p - 1) / 2, p) == p - 1){
                r = modpow(a, (p - 1) / 4, p);
                break;
            }
        }

        ull r1 = p - r;
        if(r * r + 1 == p) r += p;
        for(ll i = r; i <= MAXN; i += p)
            comp[i] = 1;
        
        if(r1 * r1 + 1 == p) r1 += p;
        for(ll i = r1; i <= MAXN; i += p)
            comp[i] = 1;
    }


    ans[1] = 1;
    ans[2] = ans[3] = 2;
    int d = 4;
    for(ull i = 4; i <= MAXN; i += 2, d += 2){
        if(d >= 10) d -= 10;
        ans[i] = ans[i - 1] = ans[i - 2];
        if(!((1 << d) & 81)) continue;
        if(!comp[i]) ans[i]++;
    }

    //auto fin = chrono::high_resolution_clock::now();
    //chrono::duration<long double> t = fin - ini;

    //cout << t.count() << endl;
    //cout << ans[MAXN] << endl;

    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}
// g++ -x c++ -g -O2 -std=gnu++20 -static prueba2.cpp