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
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    int ans[n];
    for(int i = 1; i < n; ++i) ans[a[i - 1].second] = a[i].first;
    ans[a[n - 1].second] = a[0].first;

    for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
