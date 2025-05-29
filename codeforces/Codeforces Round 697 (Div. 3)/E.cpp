/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

#define MAXN 1000

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int fact[MAXN + 1], inv_fact[MAXN + 1];
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv_fact[MAXN] = 52180388;
    for(int i = MAXN; 0 < i; --i) inv_fact[i - 1] = 1ll * i * inv_fact[i] % MOD;

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int arr[n];
        for(int &x : arr) cin >> x;
        sort(arr, arr + n);

        int mini = arr[n - k], cnt_mini = 0;
        for(int i = n - k; i < n && arr[i] == mini; ++i) cnt_mini++;
        int all_mini = 0;
        for(int i = 0; i < n; ++i) all_mini += arr[i] == mini;

        cout << 1ll * fact[all_mini] * inv_fact[cnt_mini] % MOD * inv_fact[all_mini - cnt_mini] % MOD << '\n';
    }
}
