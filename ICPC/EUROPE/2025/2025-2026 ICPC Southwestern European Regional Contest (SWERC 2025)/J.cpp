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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);
const int MOD = 1e9 + 7;



const int MAXN = 4005;
int a[MAXN], b[MAXN];
bool dp[MAXN][MAXN], ordp[MAXN][MAXN];

bool _dp( int i, int j){
    if( i < 0 || j< 0 ) return false;
    return dp[i][j];
}

bool _ordp( int i, int j){
    if( i < 0 || j< 0 ) return false;
    return ordp[i][j];
}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t; cin >> t;


    while(t--){
        int n, m; cin >> n >> m;

        memset( dp, 0, sizeof(dp));
        memset( ordp, 0, sizeof(ordp));

        for( int i=1; i<=n; i++) cin >> a[i];
        for( int j=1; j<=m; j++) cin >> b[j];

        dp[0][0] = true;
        for( int i=0; i<=n; i++) ordp[i][0] = true;


        for( int j=1; j<=m; j++){
        for( int i=1; i<=n; i++){

            // juntar bloques
            dp[i][j] = _ordp( i-b[j], j-1);
            // tomar el que aparece
            dp[i][j] |= (  b[j] == a[i] && _dp(i-1,j-1) );



            // ir acumulando por fila 
            ordp[i][j] = ordp[i-1][j] || dp[i][j];
        }
        }
        
        if( dp[n][m]  ) cout << "YES\n";
        else cout << "NO\n";
    }
}