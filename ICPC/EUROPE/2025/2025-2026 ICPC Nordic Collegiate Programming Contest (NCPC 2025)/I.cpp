#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;





int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;  cin >> n >> m; n++;

    /// Input E log E
    set< pll > edges;
    for( int i=0; i<m; i++ ){
        ll a,b; cin >> a >>b ;
        edges.insert( {a,b}  );
    }

    /// Calcular CC //  E log E
    int cc[n] = {};
    set< pll >::iterator it;
    for (it=edges.begin(); it!=edges.end(); ++it){
        //  A sigue a B
        int a = it -> first;
        int b = it -> second;
        //  B no sigue a A
        if( edges.find( {b,a} ) == edges.end() ){
            cc[b]++;
        }
    }


    /// Buscar maximo CC
    int maxi = cc[1], nodo=1;

    for( int i=2; i<n; i++ ){
        if(  cc[i] > maxi    ){
            maxi = cc[i];
            nodo = i;
        }
    }

    cout << nodo << ' ' << maxi << '\n';





}