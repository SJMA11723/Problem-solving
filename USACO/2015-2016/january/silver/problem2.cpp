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
    ifstream cin("div7.in");
    ofstream cout("div7.out");

    int n; cin >> n;
    int64_t arr[n + 1]; arr[0] = 0;
    for(int i = 1; i <= n; arr[i] += arr[i - 1], ++i) cin >> arr[i];

    int ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = i + ans; j <= n; ++j)
            if((arr[j] - arr[i - 1]) % 7 == 0) ans = max(ans, j - i + 1);
    cout << ans << '\n';
}
