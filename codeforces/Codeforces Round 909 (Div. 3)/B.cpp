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
        int n; cin >> n;
        long long arr[n + 1]; arr[0] = 0;
        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }

        long long ans = 0;
        for(int i = 1; i <= n; ++i){
            if(n % i) continue;
            long long mini = LLONG_MAX, maxi = 0;
            for(int j = i; j <= n; j += i){
                mini = min(mini, arr[j] - arr[j - i]);
                maxi = max(maxi, arr[j] - arr[j - i]);
            }
            ans = max(ans, maxi - mini);
        }
        cout << ans << '\n';
    }
}
