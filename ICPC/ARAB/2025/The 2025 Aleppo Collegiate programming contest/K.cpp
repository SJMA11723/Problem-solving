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
        int n,x; cin >> n >> x;
        vi arr(n);
        for( int &a : arr )cin >> a;

        int ans = 0;
        for( int i=x; i<n; i++ ){
            ans |= arr[i];
        }
        cout << ans << '\n';

    }
}
