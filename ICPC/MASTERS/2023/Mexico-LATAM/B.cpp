#include <bits/stdc++.h>

using namespace std;

int ceil_1000(int n){
    return (n + 999) / 1000 * 1000;
}

int floor_1000(int n){
    return n / 1000 * 1000;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, n, m; cin >> c >> n >> m;
    int64_t cnt[c + 1] = {};
    for(int i = 0; i < n; ++i){
        int d; cin >> d;
        cnt[d]++;
    }

    int64_t ans[55] = {};
    ans[0] = n;
    for(int i = 1; i <= 54; ++i){
        for(int j = c; 0 <= j; --j){
            if(j * 2 > c){
                int64_t old_cnt = cnt[j];
                cnt[j] = 0;
                cnt[ceil_1000(j)] += old_cnt;
                cnt[floor_1000(j)] += old_cnt;
            } else {
                cnt[2 * j] += cnt[j];
                cnt[j] = 0;
            }
        }

        ans[i] = accumulate(cnt, cnt + c + 1, 0ll);
    }

    while(m--){
        int x; cin >> x;
        cout << ans[x] << '\n';
    }
}
