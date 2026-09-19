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
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

template<typename A, typename B> ostream&operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}
//template<typename C, typename T = typename enable_if<!is_same<C, string::value, typename C::value_type>::type>
//ostream& ope

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;cin >> n;


    ll Tengo = 0, Lengo = 0;


    for( int i=1; i<=n; i++){
        if( i%2 == 1) Tengo +=i;
        if( i%2 == 0) Lengo +=i ;
    }

    // tengo es el mayor
    if( Tengo < Lengo ) swap(Tengo, Lengo);

    ll dif = Tengo - Lengo;


    if( dif % 2 == 0) cout << "PAR\n";
    else cout << "IMPAR\n";
}