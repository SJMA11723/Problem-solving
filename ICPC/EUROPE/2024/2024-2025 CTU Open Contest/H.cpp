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
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 

    int n; cin >> n;

    ordered_set llegadas;
    ll ans = 0;
    int idx = 0;

    for( int i=0; i<n; i++ ){
        int pi; cin >> pi;
        
        if( pi==0 ) continue;

        vi aDonde(pi);
        for( int &x: aDonde ) cin >> x;

        // para cada una de als direcciones finales ver si choca con uno anterior
        for( int &x: aDonde ) ans += sz(llegadas) - llegadas.order_of_key({x + 1, -1});

        // meterlos al multiset
        for( int &x: aDonde ) llegadas.insert({x, idx++});

        //cout <<  ans << '\n';
    }
    
    cout <<  ans << '\n';
}