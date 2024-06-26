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
    int t; cin >>t;
    while(t--){
        int n, L, R; cin >> n >> L >> R;
        int64_t arr[n + 1]; arr[0] = 0;
        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }

        int64_t ans = 0;
        for(int i = 1; i <= n; ++i){
            int l = i, r = n;
            while(l < r){
                int mid = l + (r - l) / 2;
                if(arr[mid] - arr[i - 1] >= L) r = mid;
                else l = mid + 1;
            }

            int64_t sum = arr[l] - arr[i - 1];
            if(L <= sum && sum <= R){
                ans++;
                i = l;
            }
        }
        cout << ans << '\n';
    }
}
