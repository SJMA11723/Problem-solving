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

const int MOD = 1e9 + 7;
const ll inv2 = 500000004;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    int arr[q];
    for(int &x : arr) cin >> x;

    int ans[n + 1] = {};
    int F = 0;
    for(int i = q - 1; 0 <= i; --i){
        ans[arr[i]] += inv2 * F % MOD;
        if(ans[arr[i]] >= MOD) ans[arr[i]] -= MOD;

        F = inv2 * (arr[i] + F) % MOD;
    }
    ans[1] += F;
    if(ans[1] >= MOD) ans[1] -= MOD;

    for(int i = 1; i <= n; ++i) cout << ans[i] << '\n';
}