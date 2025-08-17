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


    int t; cin >> t;

    while( t-- ){
        int n,m; cin >> n >> m;
        vi meses(n+1);
        for( int i=1; i<=n; i++) cin >> meses[i];
        vi acum_meses(n+1,0);
        for( int i=1; i<=n; i++) acum_meses[i] = acum_meses[i-1] + meses[i];

        while( m-- ){
            int sd,sm, ed,em; cin >> sd >> sm >> ed >> em;

            /// si el final es en otro year
            if(  sm > em || ( sm==em && sd > ed   )  ){
                int ans = ed + acum_meses[em-1];

                // la dsitacnia entre sd sm y fin de year
                int d2 = meses[sm] - sd +1;
                d2 += acum_meses[n] - acum_meses[sm];

                ans+=d2;
                 cout << ans << '\n';
            }
            /// si el finaal y el inicio es en el mismo year
            // si es el mismo mes
            else if( sm == em ){
                cout << ed - sd +1 << '\n';
            }
            // si es en meses diferenes
            else{
                // mes en el que sale
                int ans = meses[sm] - sd +1;
                // mes en el que llega
                ans +=  ed;
                // mes intermedio
                ans +=  acum_meses[em-1] - acum_meses[sm+1 -1] ;

                cout << ans << '\n';

            }

        }


    }

}
