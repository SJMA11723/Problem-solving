/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int arr[n];
    for(int &x : arr) cin >> x;
    int idx[n]; iota(idx, idx + n, 0);
    sort(idx, idx + n, [&](int i, int j){return arr[i] > arr[j];});

    ll val = 0;
    for(int i = 0; i < k; ++i) val += arr[idx[i]];

    int partitions = 1;
    sort(idx, idx + k);
    for(int i = 1; i < k; ++i) partitions = 1ll * partitions * (idx[i] - idx[i - 1]) % MOD;
    cout << val << ' ' << partitions << '\n';
}
