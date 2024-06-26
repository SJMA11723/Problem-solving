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
        int n, k; cin >> n >> k;
        int a[n], h[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> h[i];

        int ans = 0, sum = 0, cnt = 0, l = 0;
        for(int i = 0; i < n; ++i){
            if(sum + a[i] <= k && (!i || h[i - 1] % h[i] == 0)){
                cnt++;
                sum += a[i];
            } else if(!i || h[i - 1] % h[i] == 0){
                sum += a[i];
                while(sum > k) sum -= a[l++];
                cnt = i - l + 1;
            } else if(a[i] <= k){
                sum = a[i];
                cnt = 1;
                l = i;
            } else{
                sum = cnt = 0;
                l = i + 1;
            }

            ans = max(ans, cnt);
        }

        cout << ans << '\n';
    }
}
