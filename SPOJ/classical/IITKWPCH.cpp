/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXLEN 1'000'000
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

template <int len = 1> void count_pairs(const int sz, const int n, string arr[], int64_t &ans) {
    if(sz > len) {
        count_pairs<std::min(len * 2, MAXLEN)>(sz, n, arr, ans);
        return;
    }
    bitset<len> sets[10];

    for(int i = 0; i < n; ++i)
    for(char c : arr[i]) sets[c - '0'].set(i);

    int lim = 1 << 10;

    for(int mask = 1; mask < lim; ++mask){
        bitset<len> inter; inter.flip();
        for(int i = 0; i < 10; ++i){
            if(is_on(mask, i)){
                inter &= sets[i];
            }
        }

        int cnt = inter.count();

        ans += 1ll * cnt * (cnt - 1) / 2 * (__builtin_parity(mask) ? 1 : -1);
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string arr[n];
        for(string &s : arr) cin >> s;

        int64_t ans = 0;
        count_pairs(n, n, arr, ans);
        cout << ans << '\n';
    }
}
