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
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

int bin_exp(int a, int b){
    if(!b) return 1;
    int tmp = bin_exp(a, b / 2);
    if(b & 1) return 1ll * tmp * tmp % MOD * a % MOD;
    return 1ll * tmp * tmp % MOD;
}

#define MAXN 1000000
int sum[MAXN + 1];

int inv(int n){
    return bin_exp(n, MOD - 2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 3; i <= MAXN; ++i){
        sum[i] += sum[i - 1] + (i - 1) / 2;
        if(sum[i] >= MOD) sum[i] -= MOD;
    }

    int k; cin >> k;
    int ans = 1;
    while(k--){
        int n; cin >> n;
        int cur = sum[n] * 6ll % MOD;
        cur = 1ll * cur * inv(n) % MOD;
        cur = 1ll * cur * inv(n - 1) % MOD;
        cur = 1ll * cur * inv(n - 2) % MOD;
        ans = 1ll * ans * cur % MOD;
        cout << ans << '\n';
    }
}