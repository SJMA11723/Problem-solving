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

#define is_on(n, i) ((n) & (1ll << (i)))

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a, b; cin >> a >> b;
    pll ans = {__builtin_popcountll(b), b};

    while(a <= b){
        ans = min(ans, {__builtin_popcountll(a), a});

        bool ok = false;
        for(int k = 0; k < 60; ++k){
            if(is_on(a, k)){
                a += (1ll << k);
                ok = true;
                break;
            }
        }
        if(!ok) break;
    }
    cout << ans.se << '\n';
}

