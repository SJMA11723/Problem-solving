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

int dar_k( int n ){
    // par
    if( n%2 ==0 ) return n/2-1;
    //impar
    return (n-1)/2;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


//    for( int i=3; i<12; i++ ) cout << i << ' ' << minimo(i) <<'\n';

    int t; cin>> t;


    // area s/2

    while( t-- ){
        int n,s; cin >> n >> s;

        if( n == 3 ){
            cout << "YES\n";
            cout << "0 0\n";
            cout << s << " 0\n";
            cout << "0 1\n";
            continue;
        }

        // s/2 < minimo
        int k = dar_k(n);

        int doble_minimo = 2*k;
        if( n%2 == 1 ) doble_minimo--;


        if( s < doble_minimo ){
            cout << "NO\n";
            continue;
        }

        /// s >= k*2
        cout << "YES\n";
        int dif = s - doble_minimo;

        // poner picos
        for( int i=1; i<=k-1; i++  ){
            cout << i << " 1\n";
            cout << i+1 << " 2\n";
        }

        // poner ultimo pico para impar
        if( n%2==1 ){
            cout << k << " 1\n";
            cout << k+1 << ' ' << 1+dif << "\n";
        }
        // poner ultimo pico para par
        else{
            cout << k << " 1\n";
            cout << k+1 << ' ' << 2+dif << "\n";

        }

        // par
        if( n%2 == 0 ){
            cout << k+1 << " 1\n";
            cout << "1 0\n";

        }
        // impar
        else{
            cout << k+1<< " 0\n";
        }


    }

}
