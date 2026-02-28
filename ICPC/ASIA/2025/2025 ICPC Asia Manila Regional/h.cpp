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
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define DEBUG if(deb)

const int deb = false;
const ll MOD = 104206969;
const int MAXN = 1e7 + 2;

void criba( int n, vi & primos){
    primos.clear();
    if( n < 2 ) return;

    vector<bool> no_primo(n+1);
    no_primo[0] = no_primo[1] = true;
    for( ll i= 3; i*i <= n; i+= 2 ){
        if( no_primo[i] ) continue;
        for( ll j=i*i; j <=n ; j+= 2*i ){
            no_primo[j] = true;
        }
    }
    primos.pb(2);
    for( int i=3; i<=n; i+=2 )
        if( !no_primo[i]) primos.pb(i);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> primos;
    vector<int> primosGemelos; 
    criba(MAXN, primos);
    // criba(1000, primos);
    int anterior = primos[0];
    for( int i=0; i< primos.size()-1; i++ ){
        if( primos[i+1] - primos[i] == 2  ){    
            primosGemelos.pb(primos[i]);
        }
    }
    
    // for( int x : primosGemelos ) cout << x << ' ' << x+2 <<'\n';
    // DEBUG cout << primos.size() << " " << primosGemelos.size() << '\n';


    // acumulado
    vector<ll> acum_primos( primos.size() );
    vector<ll> acum_primosGemelos( primosGemelos.size() );
    acum_primos[0] = primos[0];
    acum_primosGemelos[0] = primosGemelos[0];
    for( int i=1; i< primos.size(); i++ ){
        acum_primos[i] = (acum_primos[i-1] + primos[i] )%MOD;
    }
     for( int i=1; i< primosGemelos.size(); i++ ){
        acum_primosGemelos[i] = (acum_primosGemelos[i-1] + primosGemelos[i])%MOD;
    }

    // casoss 
    int t; cin >> t;
    while( t-- ){
        ll n; cin >> n;
        ll k; cin >> k;

        if( k> 4 ){
            cout << "0\n"; continue;
        }

        if( k ==1 ){
            cout << n << "\n"; continue;
        }

        if( n<=2 ){ 
            cout << "0\n"; continue;
        }

        if( k== 2 ){
            auto it= lower_bound( all(primos), n );
            it--;

            int pos = it - primos.begin();
            ll cantidadDePrimosMenores = pos +1;
            ll sumaDePrimosMenores = acum_primos[pos];

            DEBUG cout << "lower_bound " << *it <<'\n';
            DEBUG cout << "cantidadDePrimosMenores " << cantidadDePrimosMenores <<'\n';
            DEBUG cout << "sumaDePrimosMenores " << sumaDePrimosMenores <<'\n';
            
            //  n * cantidadDePrimosMenores - sumaDePrimosMenores
            ll ans = ((n * cantidadDePrimosMenores) %MOD ) ;
            ans = ( ans - sumaDePrimosMenores +MOD)  %MOD;
            cout << ans << '\n';
            continue;
        }

        
        // --- para 3 y 4 ---
        if( k == 3 ){
            int resta = 2;
            ll nn = n - resta;

            auto it= lower_bound( all(primosGemelos), nn );
            DEBUG cout << "iterador tomado " << *it << '\n';
            if( it == primosGemelos.begin() ){
                cout << "0\n";
                continue;
            }
            it--;
                
            int pos = it - primosGemelos.begin();
            ll cantidadDePrimosMenores = pos +1;
            ll sumaDePrimosMenores = acum_primosGemelos[pos];
            
            DEBUG cout << "lower_bound " << *it <<'\n';
            DEBUG cout << "cantidadDePrimosMenores " << cantidadDePrimosMenores <<'\n';
            DEBUG cout << "sumaDePrimosMenores " << sumaDePrimosMenores <<'\n';
            
            //  n * cantidadDePrimosMenores - sumaDePrimosMenores
            ll ans = ((nn * cantidadDePrimosMenores) %MOD ) ;
            ans = ( ans - sumaDePrimosMenores +MOD)  %MOD;

            if( k == 3 ){
                ans  = (ans*2) %MOD;
                cout << ans << '\n';
            }

        }
        

        if( k == 4 ){
            if( n >= 8 ){
                cout << n - 7 << '\n';
            }else{
                cout << "0\n";
            }
          
        }
        
        
        DEBUG cout << "\n";
    }

} 