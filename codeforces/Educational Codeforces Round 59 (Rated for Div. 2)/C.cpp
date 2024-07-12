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
    int a[n];
    for(int &x : a) cin >> x;

    vector<pair<int, int>> consecutive;
    char cur = 0;
    for(int i = 0; i < n; ++i){
        char c; cin >> c;
        if(c != cur){
            sort(consecutive.begin(), consecutive.end());
            for(int i = 0; i < max(0, (int)consecutive.size() - k); ++i) a[consecutive[i].second] = 0;
            consecutive.clear();
        }

        consecutive.push_back({a[i], i});
        cur = c;
    }
    sort(consecutive.begin(), consecutive.end());
    for(int i = 0; i < max(0, (int)consecutive.size() - k); ++i) a[consecutive[i].second] = 0;

    int64_t ans = 0;
    for(int i = 0; i < n; ++i) ans += a[i];
    cout << ans << '\n';
}
