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
        int A[n];
        for(int i = 0; i < n; ++i) cin >> A[i];

        int ans = 0, maxi = 0, sum = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            if(i >= k) continue;
            maxi = max(x, maxi);
            sum += A[i];
            ans = max(ans, sum + maxi * max(0, k - i - 1));
        }
        cout << ans << '\n';
    }
}
