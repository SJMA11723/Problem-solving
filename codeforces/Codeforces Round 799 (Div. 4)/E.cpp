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
        int n, s;
        cin >> n >> s;
        int acc[n + 1];
        acc[0] = 0;
        for(int i = 1; i <= n; ++i){
            cin >> acc[i];
            acc[i] += acc[i - 1];
        }

        if(acc[n] < s){
            cout << "-1\n";
            continue;
        }

        int ans = 1e9;
        for(int i = 1; i <= n; ++i)
            ans = min(ans, n - int(upper_bound(acc + i, acc + n + 1, s + acc[i - 1]) - acc) + i);

        cout << ans << '\n';
    }
}
