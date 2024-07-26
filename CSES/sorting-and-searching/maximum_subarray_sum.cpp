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
    int n; cin >> n;
    int64_t ans, sum;
    cin >> sum; ans = sum;
    for(int i = 1; i < n; ++i){
        int64_t x; cin >> x;
        sum = max(sum + x, x);
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}
