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
    int l[n], r[n];
    int pref_maxl[n], pref_minr[n];
    cin >> pref_maxl[0] >> pref_minr[0];
    for(int i = 1; i < n; ++i){
        cin >> l[i] >> r[i];
        pref_maxl[i] = max(l[i], pref_maxl[i - 1]);
        pref_minr[i] = min(r[i], pref_minr[i - 1]);
    }

    int ans = 0, suff_maxl = -1, suff_minr = INT_MAX;
    for(int i = n - 1; 0 < i; --i){
        ans = max(ans, min(pref_minr[i - 1], suff_minr) - max(pref_maxl[i - 1], suff_maxl));

        suff_maxl = max(l[i], suff_maxl);
        suff_minr = min(r[i], suff_minr);
    }
    ans = max(ans, suff_minr - suff_maxl);

    cout << ans << '\n';
}
