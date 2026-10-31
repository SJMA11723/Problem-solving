#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
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
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = (b); i < (b); ++i)

const int MOD = 1e9 + 7;

template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream &operator<<(ostream  &os, const C &v);

template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}

template<typename C, typename T>
ostream& operator<<(ostream &os, const C &v){
    string sep;
    for(const T &x : v) os << sep << x, sep = " ";
    return os;
}
constexpr const char *RST="\033[0m", *GREEN="\033[1;32m",
*YELLOW="\033[1;33m", *CYAN="\033[1;36m", *RED="\033[1;31m";

template<typename ...Args>
void logger(const char *col, string vars, Args&&... values){
    cerr << col << '[' << vars << "] = " << RST;
    ((cerr << " [" << values << ']'), ...);
    cerr << '\n';
}


#ifdef LOCAL
    #define DEBUG if(true)
    #define SALTO (cerr << '\n')
    #define LOG(...) logger("", #__VA_ARGS__, __VA_ARGS__)
    #define LOGC(c, ...) logger(c, #__VA_ARGS__, __VA_ARGS__)
    #define COL(c, ...) (cerr << c << __VA_ARGS__ << RST << '\n')
#else 
    #define DEBUG if(false)
    #define SALTO 
    #define LOG(...)
    #define LOGC(c, ...)
    #define COL(c, ...)
#endif

void update_block(int cur_block, vi &cnt, int a[], vpii pending[], int n, int len){
    if(sz(pending[cur_block]) == 0) return;
    
    int L = min(cur_block * len, n - 1), R = min((cur_block + 1) * len - 1, n - 1);
    if(pending[cur_block].back().se < 0){
        pending[cur_block].clear();
        for(int i = L; i <= R; ++i) cnt[i] = 0;
        return;
    }

    reverse(all(pending[cur_block]));
    for(auto it = pending[cur_block].begin(); it != pending[cur_block].end(); ++it){
        if(it->se < 0){
            pending[cur_block].erase(it, pending[cur_block].end());
            for(int i = L; i <= R; ++i) cnt[i] = 0;
            break;
        }
    }
    
    while(sz(pending[cur_block])){
        int b, v; tie(b, v) = pending[cur_block].back();
        pending[cur_block].pop_back();

        for(int i = b; L <= i; --i){
            int mini = min(1ll*a[i] - cnt[i], llabs(v));
            cnt[i] += mini;
            v -= mini;
        }
    }
}

int main(){
    #ifdef LOCAL
        ifstream cin("test.in");
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif

    int n, m; cin >> n >> m;
    int a[n];
    int len = sqrt(n), N = (n + len - 1) / len;
    vll block(N);
    ll block_cap[N] = {};
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        block_cap[i / len] += a[i];
    }

    vpii pending[N];
    vi cnt(n);

    LOG(len, N);

    while(m--){
        int t; cin >> t;
        if(t == 1){
            int b, v; cin >> b >> v;
            b--;
            int first_block = b / len;
            LOG(b, v, first_block);

            
            // si cubre bloque parcial tomamos solo el prefijo afectado
            if((b + 1) % len){
                update_block(first_block, cnt, a, pending, n, len);
                ll sum = 0, cap_upto = 0;
                for(int i = min(first_block * len, n - 1); i <= b; ++i){
                    sum += cnt[i];
                    cap_upto += a[i];
                }
                int mini = min(cap_upto - sum, 1ll * v);
                block[first_block] += mini;
                LOGC(GREEN, block[first_block], v);
                pending[first_block].pb({b, v});
                v -= mini;
                LOGC(RED, v);
                first_block--;
            }

            for(int i = first_block; 0 <= i && v; --i){
                int mini = min(block_cap[i] - block[i], 1ll*v);
                block[i] += mini;
                LOGC(GREEN, i, block[i], v);
                pending[i].pb({min(len * (i + 1) - 1, n - 1), v});
                v -= mini;
                LOGC(RED, v);
            }

            LOG(cnt);
            LOG(block);
        } else {
            int l, r; cin >> l >> r;
            l--, r--;
            LOGC(CYAN, l, r);
            ll ans = 0;
            if(l % len){
                LOGC(RST, "BLOQUE PARCIAL", l);
                update_block(l / len, cnt, a, pending, n, len);
                for(int i = l; i <= r && i % len; ++i){
                    ans += cnt[i];
                    block[i / len] -= cnt[i];
                    cnt[i] = 0;
                }
            }

            if((r + 1) % len && (l / len != r / len || l % len == 0)){
                LOGC(RST, "BLOQUE PARCIAL", r);
                update_block(r / len, cnt, a, pending, n, len);

                for(int i = r; l <= i && (i + 1) % len; --i){
                    ans += cnt[i];
                    block[i / len] -= cnt[i];
                    cnt[i] = 0;
                }
            }

            while(l % len) l++;
            while((r + 1) % len) r--;

            LOG(ans);
            LOG("BLOQUES COMPLETOS", l, r);
            if(!m){
                update_block(0, cnt, a, pending, n, len);
                LOGC(RED, cnt);
                LOGC(RED, block);
            }

            if(l <= r){
                int min_block = l / len, max_block = r / len;
                LOG(min_block, max_block);
                for(int i = min_block; i <= max_block; ++i){
                    ans += block[i];
                    block[i] = 0;
                    pending[i].pb({0, -1});
                }
            }

            cout << ans << '\n';
        }
        SALTO;
    }
}

