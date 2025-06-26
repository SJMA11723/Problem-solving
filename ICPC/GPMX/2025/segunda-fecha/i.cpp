#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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


    ll fibo[500];
    fibo[0] = 1;
    fibo[1] = 2;

    int maxi = 0;
    for( int i=2; i<500; i++ ){
        fibo[i] = fibo[i-1] + fibo[i-2];
        //cout << i << ' ' << fibo[i] << '\n';
        maxi = i;
        if(  fibo[i]  >= 10000000009 ) break;
    }

    int q; cin >>  q;
    ll k,x;

    while( q-- ){
        cin >> x >> k;

        // buscar el primer numeor de fibo ams grande que k
        int ans = 0;
        while( fibo[ans]  * x < k ) ans++;

        cout << ans + 1<< '\n';
    }


}
    