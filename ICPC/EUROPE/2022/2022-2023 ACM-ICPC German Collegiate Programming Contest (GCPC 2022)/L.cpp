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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(z) (int)(x).size()

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int a,b,n; cin >>  a >> b >> n;

    // solo se puede si n | a*b // FE
    if( a * b % n ){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int x = gcd(a,n);
    int y = n/x;
    // x * y = n   x | a     


    if( b % y ){ // creoq ue jamas deberia entrar aqui pero x
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // x * y = n   //   x | a   //    y | b
    // x * lx = a  //  y * ly = b
    int lx = a/x;
    int ly = b/y;
    // lx es longitud // x es catindad
    // cout << "x: " << x << " y:" << y << '\n';
    // cout << "lx: " << lx << " ly:" << ly << '\n';

    for(int i=0; i<a; i++){
    for(int j=0; j<b; j++){
        int id_horizontal = j /ly;
        int id_vertical = i /lx;

        int id = id_vertical* (b/ly) + id_horizontal;
        char c = id +'A';
        cout << c;
    }
    cout << '\n';
    }



}