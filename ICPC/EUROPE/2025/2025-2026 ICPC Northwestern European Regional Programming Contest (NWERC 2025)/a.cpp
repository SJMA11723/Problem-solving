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

mt19937_64 generator(chrono::steady_clock::now().time_since_epoch().count());

uniform_int_distribution<ll> distr(1, 1e18);

const int MOD = 1e9 + 7;

vpii ans;
vi arr;

void op(int i, int j){
    ans.pb({i + 1, j + 1});
    int a = arr[i];
    int b = arr[i + 1];
    int c = arr[i + 2];
    arr.erase(arr.begin() + i, arr.begin() + i + 3);
    arr.insert(arr.begin() + j, {a, b, c});
}

/**
 * Suponemos que el arreglo se ve como:
 * ...abxyc... y quedemos intercambiar x con y
 * arr[i] = x.
 * 
 *                   i
 *                   |
 *                   v
 * op(i - 2, i) -> ycabx
 * op(i - 1, i) -> yxcab
 * op(i - 2, i) -> abyxc
 */
void swap(int i){
    op(i - 2, i);
    op(i - 1, i);
    op(i - 2, i);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    arr.resize(n);
    for(int &x : arr) cin >> x;

    for(int i = 0; i + 3 < n; ++i){
        reset:
        int pos_min = i;
        for(int j = i; j < n; ++j){
            if(arr[j] < arr[pos_min])
                pos_min = j;
        }

        if(pos_min + 2 < n){ // mxy|
            op(pos_min, i);
        } else if(pos_min + 1 < n){ // xmy|
            op(pos_min - 1, i);
            if((i + 1) + 2 < n) op(i + 1, i);
            else goto reset;
        } else { // xym|
            op(pos_min - 2, i);
            if((i + 2) + 2 < n) op(i + 2, i);
            else goto reset;
        }
    }

    if(arr[n - 2] > arr[n - 1]){
        op(n - 3, n - 4);
        swap(n - 3);
        op(n - 4, n - 3);
    }

    if(arr[n - 3] > arr[n - 2]){
        swap(n - 3);
    }

    if(arr[n - 2] > arr[n - 1]){
        op(n - 3, n - 4);
        swap(n - 3);
        op(n - 4, n - 3);
    }

    cout << sz(ans) << '\n';
    for(auto [i, j] : ans) cout << i << ' ' << j << '\n';
}