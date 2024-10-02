#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, f; cin >> n >> k >> f;
    int64_t friend_mask[f] = {};
    for(int i = 0; i < f; ++i){
        int cnt; cin >> cnt;
        while(cnt--){
            int x; cin >> x; x--;
            friend_mask[i] |= (1ll << x);
        }
    }

    int ans = 0;
    int lim = (1 << f);
    for(int mask = 1; mask < lim; ++mask){
        int64_t mask_dislike = 0;
        for(int i = 0; i < f; ++i)
            if(is_on(mask, i)) mask_dislike |= friend_mask[i];
        if(n - __builtin_popcountll(mask_dislike) >= k)
            ans = max(ans, __builtin_popcount(mask));
    }
    cout << ans << '\n';
}
