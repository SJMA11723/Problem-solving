#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int64_t MOD = 1e9 + 7;


int calc( string s){
    bool esUnNumero = true;
    string sinPa = "";
    for( char c: s){
        // si ya encontre parentesiss 
        if( !esUnNumero ) sinPa+=c;
        
        if( c =='(') esUnNumero = false;
    }

    /* cout <<  s<< '\n'; */

    if( esUnNumero ) return stoi(s);
    return stoi(sinPa);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    map<string, int> nombre2id;
    vector<string> id2nombre;

    vpii juegos;
    vi countGanadas(1025,0);

    int n,k;  cin >> k >> n;

    
    string a,b,s;
    int ga,gb;
    for( int i=1; i< (1<<k);i++ ){
        cin >> a;
        cin >> s;
        ga = calc(  s );
        
        cin >> s;  // - 
   
        cin >> s;
        gb = calc(  s );
        cin >> b;
        
       if( !nombre2id.count(a)  ){
            id2nombre.push_back(a);
            nombre2id[a] = id2nombre.size()-1;
       }
        if( !nombre2id.count(b)  ){
            id2nombre.push_back(b);
            nombre2id[b] = id2nombre.size()-1;
       }

        // tomar los id / primero el que gano
        int id_a = nombre2id[a];   
        int id_b = nombre2id[b];
        if( ga < gb ) swap(id_a,id_b);

        // guarda la pareja de este partido, primero el que gano
        juegos.push_back( {id_a, id_b} );
        countGanadas[id_a]++;
        /* cout << a << " " << ga << "  "<< b << " " << gb << "\n"; */
    }


    map<pii,pii> arbol;
    for( pii juego: juegos ){
        int g = juego.fi, p = juego.se;
        int numi = min( countGanadas[g],countGanadas[p]  );
        arbol[ {g,numi} ] = {g,numi+1};
        arbol[ {p,numi} ] = {g,numi+1};
    }
    
    while( n-- ){
        cin >>a >> b;
        int cero = 0;
        pii aa= {nombre2id[a], cero};
        pii bb= {nombre2id[b], cero};

        while(aa != bb){
            aa = arbol[aa];
            bb = arbol[bb];

        }
        cout << aa.se  << '\n';


    }




}