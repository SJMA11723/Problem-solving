#include<bits/stdc++.h>

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

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();


    int t; cin >> t;

    while( t-- ){
        int n;  cin >> n;
        string s; cin >> s;


        /// buscar la cadena mas larga de cosas consecutivas
        int pos_ans = 1, cadena=1;
        char ant = s[0];

        for( int i=1; i<n; i++ ){
            if( s[i] ==  ant )cadena++;
            else cadena = 1;

            pos_ans = max(pos_ans, cadena);

            ant = s[i];
        }

        /// juntar la cadena incial y la ams larga
        int otra_ans= 0;
        for( int i=0; i<n && s[i]==s[0]; i++ ) otra_ans++;

        // bsucar cadena mas alrga sigueinte
        int busca = 0; cadena=0;
        for( int i=otra_ans; i<n ; i++ ){
            if( s[i]== s[0] ) cadena++;
            else cadena = 0;
            busca = max(busca, cadena);

        }


        cout << max(pos_ans, busca+otra_ans) << '\n';
    }


}

