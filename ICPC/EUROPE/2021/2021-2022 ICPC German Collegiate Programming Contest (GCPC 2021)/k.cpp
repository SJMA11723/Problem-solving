#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
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
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pb push_back

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, 1e18);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){return os << '(' << p.fi << ", " << p.se << ')';}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream & operator<<(ostream &os, const C &v){string sep;for(const T &x : v) os << sep << x, sep = " "; return os;}

#define PRINT(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}

const int MOD = 1e9 + 7;

const int MAXN = 1e6 +2;
vi g[MAXN];
int color[MAXN];
bool sePuedeBicolorear = true;

void DFS(int nodo, int c){
    color[nodo] = c;
    int cc = 1 - c; // color contrario

    for( int vecino :g[nodo]){
        // si no esta visitado
        if( color[vecino] == -1 ){
            DFS( vecino, cc);
        }

        // si ya fue visitado
        else{
            // y si no es el color contrario
            if( color[vecino] != cc ){
                sePuedeBicolorear = false;
                return;
            }
        }
    }
}

int init_DFS(int n){
    for( int i=0; i<=n; i++){
        color[i] = -1;
    }

    int compConx = 0;

    for( int i=1; i<=n; i++){
        if( color[i] == -1 ){
            DFS(i, 0);
            compConx++;
            if( !sePuedeBicolorear ) return -1;
        }
    }

    return compConx;
}

ll exp_bin(ll base, ll exp, ll mod){
    ll res = 1;
    while( exp >0 ){
        if( exp &1 ) res = (res*base) % mod;
        base = (base*base) % mod;
        exp >>=1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m,p; cin >> n >> m  >> p;

    int a,b;
    for( int i=0; i<m; i++){
        cin >> a >> b; 
        g[a].pb(b);
        g[b].pb(a);
    }   

    int compConx = init_DFS(n);
    // cout << compConx << '\n';
    if( compConx == -1 ){
        cout << "impossible\n";
    }else{
        ll  ans = exp_bin(2, compConx-1, p) ;
        // cout << ans <<'\n';
        ans  = (ans+1) %p;
        cout << ans << '\n';
    }
}
