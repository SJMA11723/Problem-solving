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


int n, m, x, y;
vector<int> shelves, books;

// ver si es posible colocar todos los libros usando exactamente 'k' estantes con arte
bool se_puede_con_k_estantes_con_arte(int k) {
    //if( k ==0 ) return true;
    if( k > n ) return false;

    //cout << k << ":\n  ";
    int normales = n - k;


    int i = 0; // puntero a estantes
    int j = 0; // puntero a libros

    // primero usamos los estantes con arte (capacidad y)
    for( int conteo = 0; conteo<k && i<n; ++conteo, ++i ){
        int capacidad = y;
        while( capacidad > 0 && j < m && books[j] <= shelves[i] ){
            ++j; --capacidad;
        }
    }

    //  usamos los estantes normales (capacidad x)
    for( int conteo = 0; conteo < normales && i < n; ++conteo, ++i) {
        int capacidad = x;
        while (capacidad > 0 && j < m && books[j] <= shelves[i]) {
            ++j;
            --capacidad;
        }
    }

    // Verificamos si todos los libros fueron colocados
    //cout << (j == m) << '\n';
    return j == m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x >> y;

    shelves.resize(n);
    books.resize(m);

    for( int i=0; i < n; i++) cin >> shelves[i];
    for( int i=0; i < m; i++) cin >> books[i];

    sort(shelves.begin(), shelves.end());
    sort(books.begin(), books.end());

    // Bbs max k
    int l = 0, r = n, mejor_k = -1;

    while( l <= r){
        int mid = (l + r) / 2;
        if( se_puede_con_k_estantes_con_arte(mid) ){
            mejor_k = mid;
            l = mid+1 ;
        }else{
            r = mid-1 ;
        }
    }
    if( mejor_k == -1) cout << "impossible\n";
    else cout << mejor_k << '\n';

}
