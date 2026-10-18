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

#define MAXN 200000
#define MAXX 190
#define MAXK 4000000000000000000

ull dp[MAXN + 1][MAXX + 1];
ll max_x_para_n[MAXN + 1];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    ll k; cin >> k;

    ll max_x = 0;
    ll acum = 0;

    // llenar dp
    dp[0][0] = 1;
    for( int i=1; i<=n ;i++){
        acum = 1;
        dp[i][0] = 1;
        for( int x=1; x<= min( (ll)MAXX, (ll)(i-1)*i/2   ); x++){
            ull posans = dp[i][x-1] + dp[i-1][x];
            if( x - i >=0 ) posans -= dp[i-1][x-i];
            max_x_para_n[i] = x;
            dp[i][x] = min(posans, (ull)MAXK);
            if( acum > MAXK - posans ){  
                break;
            }
            acum+= posans;

           
        }
        max_x = max( max_x, max_x_para_n[i]);
    }
    ull permutaciones_menores = 0;
    int bloque_actual = 0;
    for( int x=0; x<=MAXX; x++){
        // print(x, permutaciones_menores);
        bloque_actual = x;
        // para pasar al sigueinte bloque tengo que
        // tener un indice k mayor que todo lo anteiro
        if( ! ( k > permutaciones_menores + dp[n][x]) ) break;

        permutaciones_menores += dp[n][x];
    }

    
    ll new_k = k - permutaciones_menores;
    //print(k, bloque_actual, new_k);

    ll x = bloque_actual; // cantidad de inversiones en este bloque // hay a lo mas (n-1)*n/2

    set<int> pending;
    for(int i = 1; i <= n; ++i) pending.insert(i);
    int ans[n + 1];
    for(int i = 1; i <= n; ++i){
        auto it = pending.begin();
        ll new_x = x;
        while(new_x >= 0 && new_k > dp[n - i][new_x]){
            new_k -= dp[n - i][new_x];
            it++;
            new_x--;
        }
        ans[i] = *it;
        pending.erase(it);
        x = new_x;
    }

    for(int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}