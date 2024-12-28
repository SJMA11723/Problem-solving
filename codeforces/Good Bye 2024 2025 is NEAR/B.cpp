/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct interval{
    int l, r, i;
    bool operator<(const interval &b){
        return make_pair(l, r) < make_pair(b.l, b.r);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        interval arr[n];
        int cnt[2 * n + 1] = {};
        int cnt2[2 * n + 1] = {};
        for(int i = 0; i < n; ++i){
            int l, r; cin >> l >> r;
            if(l == r) cnt[l] = 1, cnt2[l]++;
            arr[i] = {l, r, i};
        }

        for(int i = 1; i <= 2 * n; ++i) cnt[i] += cnt[i - 1];

        for(auto [l, r, i] : arr){
            if(l == r) cout << (cnt2[l] > 1 ? '0' : '1');
            else if(r - l + 1 <= cnt[r] - cnt[l - 1]) cout << '0';
            else cout << '1';
        }

        cout << '\n';
    }
}
