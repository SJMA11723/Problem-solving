#include<bits/stdc++.h>




using namespace std;


typedef int64_t ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;


#define fi first  
#define se suseconds_t
#define all(x) (x).begin(), (x).end
#define pb push_back

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);




    int n;  cin >> n;
    ll antx, anty; cin >>  antx >> anty;

    vll d;
    for( int i=2; i<=n; i++ ){
        int x,y; cin >> x  >> y;
        d.pb(  max(  abs(antx-x), abs(anty-y)    )  );
        antx= x;
        anty=y;
    }

    //for( int i : d ) cout << i  << ' '; cout << '\n';

    ll cotaMax = 2e9;
    ll cotaMin = 0;
    ll suma =0;
    ll signo = -1;
    for( int i=0; i<n-1; i++ ){
        signo = -signo;
        suma += d[i]*signo;

        if( signo == +1 ){
            cotaMax = min(cotaMax, suma);
        }else{
            cotaMin = max(cotaMin, suma);
        }
        //cout << suma << ' ' << cotaMin << ' ' << cotaMax << '\n';

    }

    cotaMax--; cotaMin++;
    //cout << cotaMin << ' ' << cotaMax << '\n';
    if(  cotaMax >= cotaMin ){
        cout <<  cotaMax << '\n';
    }else{
        cout << "-1\n";
    }

}