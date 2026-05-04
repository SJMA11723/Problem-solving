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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first 
#define se second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

void criba(int n, vi &lp){
    if(n < 2) return;
    
    lp.clear();
    lp.resize(n + 1);
    vi primos;
    for(ll i = 2; i <= n; ++i){
        if(!lp[i]) primos.pb(lp[i] = i);
        for(int j = 0; i * primos[j] <= n; ++j){
            lp[i * primos[j]] = primos[j];
            if(primos[j] == lp[i]) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q; cin >> n >> q;

    vi lp;
    criba(n, lp);

    vector<pair<vi, int>> factor(n + 1);
    for(int i = 1; i <= n; ++i){
        int tmp = i;
        factor[i].se = i;
        while(tmp > 1){
            factor[i].fi.pb(lp[tmp]);
            tmp /= lp[tmp];
        }
    }

    sort(all(factor));

    while(q--){
        int k; cin >> k;
        cout << factor[k].se << '\n';
    }
}