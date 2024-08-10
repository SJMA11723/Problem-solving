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
        pair<int, int> p[n];
        int ans[n];
        for(int i = 0; i < n; ++i){
            cin >> p[i].first;
            p[i].second = i;
        }
        sort(p, p + n);

        for(int i = 1; i < n; ++i) ans[ p[i - 1].second ] = p[i].first;
        ans[p[n - 1].second] = p[0].first;

        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}
