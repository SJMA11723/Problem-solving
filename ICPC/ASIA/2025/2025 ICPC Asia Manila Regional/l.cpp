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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define sz(x) (x).size()
#define all(x) (x).first(), (x).end()
#define pb push_back
#define DEBUG if(deb)

const int deb = false;
const int MOD = 1006903069;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    // ifstream cin("in.txt");

    int n; cin >> n;
    ll x; int t, k;

    map< int, pair<ll, bool> > sumas[n];


    DEBUG cout << "leido n\n";
    int A;  cin >> A;
    while( A-- ){
        cin >> t >> k >> x;
        if( x>= MOD) x%= MOD; k--; t--;
        sumas[t][k] = {x, false};
    }
    DEBUG cout << "leido A\n";
    int B; cin >> B;
    while( B-- ){
        cin >> k >> t >> x;
        if( x>= MOD) x%= MOD; k--; t--;
        auto search = sumas[t].find(k);
        bool existe = (search != sumas[t].end() ); 
        if( existe  ){
            sumas[t][k].first *= x;
            sumas[t][k].first %= MOD;
            sumas[t][k].second = true;
        }
    }
     DEBUG cout << "leido B\n";
    ll ans = 0;
    for( int t=0; t<n; t++){
    for( const auto & [key, value]: sumas[t]){
        if( value.second ) ans = (ans + value.first) %MOD;
    }}
    cout << ans << '\n';
}