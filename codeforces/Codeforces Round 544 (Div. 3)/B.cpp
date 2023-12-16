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
    int n, k; cin >> n >> k;
    int rem[k] = {};
    for(int i = 0; i < n; ++i){
        int d; cin >> d;
        rem[d % k]++;
    }

    long long ans = 0;
    for(int i = 1; i <= k / 2; ++i){
        if(i != k - i ) ans += min(rem[i], rem[k - i]) * 2;
        else ans += rem[i] / 2 * 2;
    }
    ans += rem[0] / 2 * 2;
    cout << ans << '\n';
}
