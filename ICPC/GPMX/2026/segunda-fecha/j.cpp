/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define pb push_back
#define fi first
#define se second

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

// =============== DEBUG ============
const bool deb = 0;
#define DEBUG if(deb)

template<typename A, typename B> ostream & operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream & operator<<(ostream &os, const C &v){
    string sep;
    for(const T &x : v) os << sep << x, sep = " ";
    return os;
}
#define print(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename ...Args> void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}
// ==================================

const ll MOD = (119 << 23) + 1, root = 62;

ll modpow(ll b, ll e){
    ll ans = 1;
    for(; e; b = b * b % MOD, e /= 2) if(e & 1) ans = ans * b % MOD;
    return ans;
}

void ntt(vll &a){
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vll rt(2, 1);
    for(static int k = 2, s = 2; k < n; k *= 2, ++s){
        rt.resize(n);
        ll z[] = {1, modpow(root, MOD >> s)};
        for(int i = k; i < 2 * k; ++i) rt[i] = rt[i / 2] * z[i & 1] % MOD;
    }

    vi rev(n);
    for(int i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for(int i = 0; i < n; ++i) if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(int k = 1; k < n; k *= 2) for(int i = 0; i < n; i += 2 * k)
    for(int j = 0; j < k; ++j){
        ll z = rt[j + k] * a[i + j + k] % MOD, &ai = a[i + j];
        a[i + j + k] = ai - z + (z > ai ? MOD : 0);
        ai += (ai + z >= MOD ? z - MOD : z);
    }
}

vll conv(const vll &a, const vll &b){
    if(a.empty() || b.empty()) return {};
    int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
    int inv = modpow(n, MOD - 2);
    vll L(a), R(b), out(n);
    L.resize(n), R.resize(n);
    ntt(L); ntt(R);
    for(int i = 0; i < n; ++i) out[-i & (n - 1)] = 1ll * L[i] * R[i] % MOD * inv % MOD;
    ntt(out);
    return {out.begin(), out.begin() + s};
}

#define MAXN 200000

int fact[MAXN + 1];

vll compute(int l, int r){
    if(l == r) return {1, r};
    int mid = (l + r) / 2;
    vll L = compute(l, mid);
    vll R = compute(mid + 1, r);
    return conv(L, R);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vll S = compute(1, n);

        ll ans = 0;
        for(int k = 1; k <= n; ++k){
            ans += S[k] * fact[k] % MOD * fact[n - k + 1] % MOD;
            if(ans >= MOD) ans -= MOD;
        }
        cout << ans << '\n';
    }
}