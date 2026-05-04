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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    int sum1 = 0;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        sum1 += x;
    }

    int sum2 = 0;
    for(int i = 0; i < m; ++i){
        int x; cin >> x;
        sum2 += x;
    }

    if(sum2 >= sum1 + sum1 / 10) cout << "YES\n";
    else cout << "NO\n";
}