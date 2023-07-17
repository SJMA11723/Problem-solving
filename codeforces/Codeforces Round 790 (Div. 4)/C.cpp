/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int diff(string &s1, string &s2){
    int d = 0;
    for(int i = 0; i < s1.size(); ++i) d += abs(s1[i] - s2[i]);
    return d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        string arr[n];
        int ans = 1e9;
        for(int i = 0; i < n; ++i) cin >> arr[i];
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                ans = min(ans, diff(arr[i], arr[j]));
            }
        }
        cout << ans << '\n';
    }
}
