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
        long long sumr = 0, suml = 0, arr[n];
        long long ans = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            sumr += arr[i];
        }

        for(int i = 0; i + 1 < n; ++i){
            suml += arr[i];
            sumr -= arr[i];
            ans = max(ans, __gcd(suml, sumr));
        }
        cout << ans << '\n';
    }
}
