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

const int MAXN= 15;
string tb[MAXN];
int n;

const char BLANCA = 'B';
const char NEGRA = 'P';
const char VACIO = '.';

int dx[4] = {-1,-1,1,1};
int dy[4] = {-1,1,-1,1};

bool puedoComer( int x0, int y0, int xc, int yc, int xf, int yf){
    // // mover
    // int xf = x0 + 2*dx[dir];
    // int yf = y0 + 2*dy[dir];

    // si al mover me salgo
    if( xf < 0 || xf >=n ) return false;
    if( yf < 0 || yf >=n ) return false;
    
    // si donde me me muevo esta esta ocupado
    if( tb[xf][yf] != VACIO) return false;
    
    // // comer 
    // int xc = x0 + dx[dir];
    // int yc = y0 + dy[dir];

    // si no hay una ficha para comer
    if( tb[xc][yc] != NEGRA  ) return false;

    // si no me salgo Y el espacio esta dosponible Y si hay para comer
    return true;

}

int len = 1;
int maxNumeroComer(int x0, int y0){
    DEBUG{
        for( int i=0; i< len; i++) cout << " ";
        cout << x0 << "" << y0 << "\n";
    }
    len++;
    
    int cuantasMePuedoComer = 0;
    for( int d=0; d<4; d++){
        // mover
        int xf = x0 + 2*dx[d];
        int yf = y0 + 2*dy[d];

        // comer 
        int xc = x0 + dx[d];
        int yc = y0 + dy[d];
    
        if( !puedoComer(x0,y0,  xc,yc,  xf,yf) )continue;

        // comer la pieza
        tb[xc][yc] = VACIO;
        
        int r =  1 + maxNumeroComer(xf,yf);
        cuantasMePuedoComer = max(cuantasMePuedoComer, r );

        // des-comer la pieza // arreglar a como esyaba
        tb[xc][yc] = NEGRA;
    }

    len--;
    return cuantasMePuedoComer;
}


int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);



    cin >> n;

    for( int i=0; i<n; i++){
        cin >> tb[i];
    }
    

    int maxLongitud = 0;
    for( int x=0; x<n; x++){
    for( int y=0; y<n; y++){
        if( tb[x][y] == BLANCA ){
            DEBUG cout << "probando" << x << " " << y << "\n";
            
            tb[x][y] = VACIO;

            int r =  maxNumeroComer(x,y);
            

            maxLongitud = max(maxLongitud, r);
            
            
            tb[x][y] = BLANCA;
        }
    }}

    cout << maxLongitud << "\n";
}