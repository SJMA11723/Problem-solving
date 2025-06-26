#include <bits/stdc++.h>

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

const int MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    ll a,b,c,d,e, ans=LONG_MAX;

    for( int i=0; i<n; i++){
        cin >> a >> b >> c >> d >> e;

        if( a<= b && d<= e ){
            ans = min( ans, a+d);

        }else if( a>b &&  d<= e ){
            ll posans = b + min( d+min(a-b,c), e);
            ans = min( ans, posans  );

        }else if( a<=b &&  d>e ){
            ll posans = e + min( a+min(d-e,c), b);
            ans = min( ans, posans  );
            
        }else if( a>b &&  d>e ){
            ans = min( ans, b+e);
        }

    }

    cout << ans << '\n';
}