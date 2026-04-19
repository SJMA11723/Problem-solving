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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(z) (int)(x).size()

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

int main(){
    

    ll a,b;
    cin>>a>>b;
    a--; b--;
    if(a > b) swap(a,b);

    int ans = 1;
    if(a != b) ans++;
    
    for(ll la = 1; la < a; la++){
        ll left = a*a-la*la;
        ll lb = sqrtl(left);
        if(lb*lb == left && (la*b)%a == 0 && (lb*b)%a == 0){
            ans+=(a == b ? 1 : 2);
        }
    }
    cout<<ans<<"\n";

}