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



const bool debug = false;
#define DEBUG if(debug)

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n, a,b; cin >> n >> a >> b;

    vi pila1,pila2,ambas;
    int x;
    for(int i=0; i<a; i++){
        cin >> x; 
        ambas.pb(x); 
    }
    for( int i=0; i<b; i++){
        cin >> x;
        pila2.pb(x);
    }
    reverse( all(pila2));
    for( int x: pila2) ambas.pb(x);

    DEBUG{
        cout << "ab: ";
        for( int x: ambas ) cout << x << ' '; cout << '\n';
    }
    
    set< pii >elementos; // {indice, val}
    map< int, int > val2idx;
    for(int i=0; i<=n; i++){
        val2idx[  ambas[i] ] = i;
        elementos.insert( {i, ambas[i]});
    }

    
    int ans = 0;
    for( int i=1; i<=n; i++){
        int val = i;
        int idx = val2idx[val];
        auto ante = elementos.find( {idx, val});
  
        auto desp =  elementos.find( {idx, val});
    
        // ver si es vecino
        DEBUG cout << "buscando en " << val << '\n';
        
        if( ante != elementos.begin() ){
            ante--;
            DEBUG cout << " anterior:" << (*ante) << '\n';
            if( ante->second == 0 ){
                ans ++;
                DEBUG cout << "  encontrado\n";
            }
        }

        desp++;
        if( desp != elementos.end()){
            DEBUG cout << " despues:" << (*desp) << '\n';
            if( desp->second == 0 ){
                ans ++;
                DEBUG cout << "  encontrado\n";
            }
        }

        // eliminamos el acutual

        elementos.erase( {idx, val});
            
    }


    cout <<  ans << '\n';
}


/*
4 3 2
2 0 3
1 4
= 3
2 0 3 4 1

6 4 3
2 4 0 1
6 3 5
= 4

*/