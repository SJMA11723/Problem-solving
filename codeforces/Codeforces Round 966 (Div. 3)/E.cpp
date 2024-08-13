/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        int w; cin >> w;
        int arr[w];
        for(int &x : arr) cin >> x;

        int64_t cnt[n * m];
        for(int i = 0, acci = 0; i < n; ++i){
            if(i + k - 1 < n) acci++;
            if(k <= i) acci--;

            int accj = 0;
            for(int j = 0; j < m; ++j){
                if(j + k - 1 < m) accj++;
                if(k <= j) accj--;
                cnt[i * m + j] = 1ll * acci * accj;
            }
        }
        sort(cnt, cnt + n * m, greater<int64_t>());
        sort(arr, arr + w, greater<int>());
        int64_t ans = 0;
        for(int i = 0; i < w; ++i) ans += cnt[i] * arr[i];
        cout << ans << '\n';
    }
}
