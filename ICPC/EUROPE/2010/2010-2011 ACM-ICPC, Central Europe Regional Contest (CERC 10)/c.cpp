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
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

#define DEBUG if(deb)

const bool deb = true;
const int MOD = 1e9 + 7;

/*
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type> ostream& operator<<(ostream &os, const C &v){
    string sep; for(const T &x : v) os << sep << x, sep = " ";
    return os;
}
#define print(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args> void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}
*/

array<vi, 2> manacher(const string &s){
    int n = sz(s);
    array<vi, 2> p = {vi(n + 1), vi(n)};
    for(int z = 0; z < 2; ++z){
        for(int i = 0, l = 0, r = 0; i < n; ++i){
            int t = r - i + !z;
            if(i < r) p[z][i] = min(t, p[z][l + t]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while(L >= 1 && R + 1 < n &&  s[L - 1] == s[R + 1]) p[z][i]++, L--, R++;
            if(R > r) l = L, r = R;
        }
    }
    return p;
}

struct H{
    ull x;
    H(ull x = 0) : x(x) {}

    H operator+(H o){ return x + o.x + (x + o.x < x);}
    H operator-(H o){ return *this + ~o.x; }
    H operator*(H o){
        auto m = (__uint128_t)x * o.x;
        return H((ull)m) + (ull)(m >> 64);
    }
    ull get() const { return x + !~x; }

    bool operator==(H o)const{
        return get() == o.get();
    }

    bool operator<(H o)const{
        return get() < o.get();
    }
};

static const H C = (ll)1e11 + 3;

struct hash_interval{
    vector<H> ha, pw;

    hash_interval(string &str) : ha(sz(str) + 1), pw(ha) {
        pw[0] = 1;
        for(int i = 0; i < sz(str); ++i){
            ha[i + 1] = ha[i] * C + str[i];
            pw[i + 1] = pw[i] * C;
        }
    }

    H get_hash(int a, int b){
        return ha[b] - ha[a] * pw[b - a];
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        array<vi, 2> M = manacher(s);

        hash_interval mhash(s);
        int ans = 0;
        for(int i = 0; i < sz(s); ++i){
            int r = M[0][i];
            if(r == 0) continue;

            while(r > ans){
                //cout << i << ' ' << r << '\n';
                //if(0 <= i - 2 * r && i + 3 * r - 1 < sz(s)) cout << s.substr(i - r, 2 * r) << ' ' << s.substr(i + r, 3 * r) << '\n';
                if(0 <= i - r && i + 3 * r - 1 < sz(s) && mhash.get_hash(i - r, i + r) == mhash.get_hash(i + r, i + 3 * r)){
                    ans = max(ans, r);
                }
                r--;
            }            
        }

        cout << 4 * ans << '\n';
    }
}