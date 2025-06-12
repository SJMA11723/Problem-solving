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

    int t;cin >> t;

    while( t-- ){
        ll n; cin >> n;

        ll act = 1;
        ll ans = 1;
        for( ll i=n-1; i>= 1; i--){
            act*= i;
            act%=MOD;
            ans+= act;
            ans%=MOD;
        }

        cout << ans << '\n';


    }



}

