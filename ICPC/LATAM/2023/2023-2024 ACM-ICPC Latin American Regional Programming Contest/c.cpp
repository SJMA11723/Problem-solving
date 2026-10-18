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
typedef unsigned long long ull;
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

const int MOD = 1e9 + 7;

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

struct H{
    ull x; H(ull x = 0): x(x){}
    H operator+(H o){return x + o.x + (x + o.x < x);}
    H operator-(H o ){return *this + ~o.x;}
    H operator*(H o){auto m = (__int128_t)x * o.x;
        return H((ull)m) + (ull)(m >> 64);}
    ull get() const {return x + !~x;}
    bool operator==(H o) const { return get() == o.get();}
    bool operator<(H o) const {return get() < o.get();}
};

static const H C = (ll)1e11 + 3;

H mhash(vi &V){
    H h{};
    for(int v : V) h = h * C + v;
    return h;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K; cin >> N >> K;
    H powC[K];
    powC[0] = 1;
    for(int i = 1; i < K; ++i) powC[i] = powC[i - 1] * C;

    int C[N + 1];
    for(int i = 1; i <= N; ++i){
        cin >> C[i];
        C[i]--;
    }

    if(N < K){
        cout << "0\n";
        return 0;
    }

    int ans = 0;
    vi freq(K);
    map<H, int> min_idx;
    H cur_hash = mhash(freq);
    min_idx[cur_hash] = 0;
    int zeros = K;
    for(int i = 1; i <= N; ++i){
        freq[C[i]]++;
        cur_hash = cur_hash + powC[C[i]];
        if(freq[C[i]] == 1) zeros--;

        if(zeros == 0){
            for(int j = 0; j < K; ++j){
                freq[j]--;
                if(freq[j] == 0) zeros++;
                cur_hash = cur_hash - powC[j];
            }
        }

        
        if(min_idx.count(cur_hash)) ans = max(ans, i - min_idx[cur_hash]);
        else min_idx[cur_hash] = i;
    }

    cout << ans << '\n';
}