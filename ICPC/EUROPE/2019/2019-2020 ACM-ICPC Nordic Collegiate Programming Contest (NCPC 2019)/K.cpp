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

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    int arr[s];
    for(int &x : arr) cin >> x;
    pair<int, int> ord[s];
    for(int i = 0; i < s; ++i){
        ord[i] = {arr[i], i};
    }
    sort(ord, ord + s);

    for(int i = 0; i < s; ++i){
        int pos = ord[i].se;
        int k = min(n, d - arr[pos]);
        n -= k;
        ord[i].fi += k;
    }

    int sum = 0;
    for(int i = 0; i < s; ++i){
        int pos = ord[i].se;
        if(ord[i].fi == arr[pos]){
            sum += arr[pos];
        }
        arr[pos] = ord[i].fi - arr[pos];
    }

    if(sum < m){
        cout << "impossible\n";
        return 0;
    }

    for(int i = 0; i < s; ++i) cout << arr[i] << " \n"[i + 1 == s];
}