#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
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
#define sz(x) (int)(x).size()
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

struct node{
    ll val;
    node(): val(LLONG_MIN){}
    node(ll x):val(x){}
};

struct segment_tree{
    vector<node> nodes;

    segment_tree(int n, ll data[]){
        nodes.resize(4 * n + 1);
        build(1, n, data);
    }

    void build(int left, int right, ll data[], int pos = 1){
        if(left == right){
            nodes[pos] = node(data[left]);
            return;
        }
        int mid = (left + right) / 2;
        build(left, mid, data, pos * 2);
        build(mid + 1, right, data, pos * 2 + 1);
        nodes[pos].val = max(nodes[pos * 2].val, nodes[pos * 2 + 1].val);
    }

    ll query(int l, int r, int left, int right, int pos = 1){
        if(r < left || right < l) return LLONG_MIN;
        if(l <= left && right <= r) return nodes[pos].val;
        int mid = (left + right) / 2;
        return max(query(l, r, left, mid, pos * 2), query(l, r, mid + 1, right, pos * 2 + 1));
    }
};

bool debug = false;
#define DEBUG if(debug)


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;  cin >> n;
    int l = n+2;
    ll B[n+4];
    ll minB[n+4];
    map< ll, int >  primeraAparicion;
    map< ll, int >  segundaAparicion;

    
    ull sumaTotal = 0;
    for( int i=1; i<=n+2; i++){
        cin >> B[i];
        minB[i] = - B[i];
        sumaTotal +=B[i];
        
        // valores a indice
        if( primeraAparicion.count(B[i]) ){
            segundaAparicion[ B[i] ] = i;
        }else{
            primeraAparicion[ B[i] ] = i;
        }
    }

    segment_tree st_min(n+2, minB);
    segment_tree st_max(n+2, B);

    int indiceM = -1;
    int indiceS = -1;
    ull SS = 0, MM =0;

    // probar con cada posible M
    for( int i=1; i<=n+2; i++){
        DEBUG cout << "provando " << i << "  A: " <<  B[i] << "\n";
        // probamos a ver si este es M
        indiceM = i;
        ull M = B[i];


        // algebra
        ull sumaDeTodosExceptoM = sumaTotal - M;
        ull SporN = sumaDeTodosExceptoM; // haz las cuentas

        // S*N debe ser divisible entre N
        if( SporN % n ){
            DEBUG cout << " no fue divisible\n";
            continue;
        }
        ull S = SporN / n;
        

        // ver si S si esat en el arreglo B
        // O( log N)
        if( primeraAparicion.count(S) == 0 ) continue;
        indiceS =  primeraAparicion[S];
        // si de casuliadad M es la primera aparicion 
        // entonces S debe ser la segunda
        if(  indiceM == primeraAparicion[S] ){
            if( segundaAparicion.count(S) == 0) continue;
            else indiceS = segundaAparicion[S];
        }


        
      
        DEBUG{

            cout << " indiceM " << indiceM <<"\n";
            cout << " M " << M <<"\n";
            cout << " indiceS " << indiceS <<"\n";
            cout << " S " << S <<"\n";
        }


        ll menor_aparicionSoM = indiceM;
        ll mayor_aparicionSoM = indiceS;
        if( menor_aparicionSoM > mayor_aparicionSoM) swap(menor_aparicionSoM, mayor_aparicionSoM);
        
        ll max_rango1 = 0;
        ll min_rango1 = LLONG_MAX;
        if( 1 <= menor_aparicionSoM-1 ){ 
            max_rango1 = st_max.query( 1, menor_aparicionSoM-1,     1,n+2); 
            min_rango1 = -st_min.query( 1, menor_aparicionSoM-1,     1,n+2); 
        }

        ll max_rango2 = 0;
        ll min_rango2 = LLONG_MAX;
        if( menor_aparicionSoM +1 <= mayor_aparicionSoM - 1){
            max_rango2 = st_max.query(  menor_aparicionSoM +1 , mayor_aparicionSoM - 1,     1, n+2 );
            min_rango2 = -st_min.query(  menor_aparicionSoM +1 , mayor_aparicionSoM - 1,     1, n+2 );
        }

        ll max_rango3 = 0;
        ll min_rango3 = LLONG_MAX;
        if( mayor_aparicionSoM +1 <= n+2 ){
            max_rango3 = st_max.query( mayor_aparicionSoM +1 ,n+2,   1,n+2 ); 
            min_rango3 = -st_min.query( mayor_aparicionSoM +1 ,n+2,   1,n+2 ); 
        }

        // tomar el maximo
        ll ll_maxiB = max( max_rango1, max_rango2);
        ll ll_miniB = min( min_rango1, min_rango2);
        ll_maxiB = max( ll_maxiB, max_rango3);
        ll_miniB = min( ll_miniB, min_rango3);

        ull maxiB = ll_maxiB;
        ull miniB = ll_miniB;

        DEBUG{
            cout <<  1 << " " <<  menor_aparicionSoM-1 << "\n";
            cout <<  menor_aparicionSoM +1  << " " << mayor_aparicionSoM - 1 << "\n";
            cout <<  mayor_aparicionSoM +1  << " " << n+2  << "\n";
            cout << "max_rango1 " << max_rango1 << "\n";
            cout << "max_rango2 " << max_rango2 << "\n";
            cout << "max_rango3 " << max_rango3 << "\n";
            cout << "maxi " << maxiB << "\n";
            cout << "mini " << miniB << "\n";
        }

        // verificar que paraca cada bi se cumple que a_i es mayor a 0
        // bi = S - a_i 
        // a_i = S - bi 
        // S - bi >=0 
        // S >= bi
        if( S < maxiB) continue;

        // verificar que cada a_i <= M
        // S - a_i >= S -M
        // Bi >= S-M
        if(M > S) continue;
        if(  miniB < S-M) continue;
        // se debe alcanza rle maxio
        if( miniB != S-M) continue;

        // si llegamos hasta aqui entonces se cumple
        DEBUG cout << " si cumplio \n";
        SS = S; MM = M;

        break;
    }


    // rearmar 
    vector<ull> A;
    for( int i=1; i<=n+2; i++){
        if( i == indiceM || i == indiceS ) continue;
        DEBUG cout << i << " " << B[i] << " " << SS - B[i]<<"\n";
        A.push_back( SS - B[i]);
    }

    sort( all(A) );

    cout << SS <<  " " << MM << "\n";

    for( int i=0; i<n; i++){
        cout << A[i] << " \n"[i==n-1];
    }


}