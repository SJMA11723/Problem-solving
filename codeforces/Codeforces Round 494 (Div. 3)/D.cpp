/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))
#define set_bit(n, i) (n |= (1ll << (i)))
#define clear_bit(n, i) (n ^= ~(1ll << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;
    map<int, int> cub;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        cub[x]++;
    }

    while(q--){
        int x; cin >> x;
        int64_t cnt = 0, ans = 0;
        for(int i = 30; 0 <= i; --i){
            if(is_on(x, i)) cnt++;
            ans += min(cnt, 1ll*cub[1 << i]);
            cnt -= min(cnt, 1ll*cub[1 << i]);
            cnt <<= 1;
        }
        cout << (cnt ? -1 : ans) << '\n';
    }
}
