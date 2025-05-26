/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

#define MAXN 200000
#define MAXLOG 29
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int fact[MAXN + 1];
    fact[0] = 1;
    for(int i = 1; i <= MAXN; ++i) fact[i] = 1ll * i * fact[i - 1] % MOD;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        int cnt[MAXLOG + 1] = {};
        for(int &x : arr){
            cin >> x;
            for(int i = 0; i <= MAXLOG; ++i) if(is_on(x, i)) cnt[i]++;
        }

        int cnt_all = 0;
        for(int i = 0; i <= MAXLOG; ++i) cnt_all += cnt[i] == n;

        int cnt_all0 = 0;
        for(int &x : arr){
            int cnt0 = 0;
            for(int i = 0; i <= MAXLOG; ++i) if(!is_on(x, i)) cnt0++;
            if(cnt0 == MAXLOG - cnt_all + 1) cnt_all0++;
        }

        cout << (cnt_all0 < 2 ? 0 : 1ll * cnt_all0 * (cnt_all0 - 1) % MOD * fact[n - 2] % MOD) << '\n';
    }
}
