#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pair<float, int> ans[n];
        for(int i = 0; i < n; ++i){
            int d, s; cin >> d >> s;
            ans[i] = {1.0 * d / s, i + 1};
        }
        sort(ans, ans + n);

        for(int i = 0; i < n; ++i) cout << ans[i].second << " \n"[i + 1 == n];
    }
}