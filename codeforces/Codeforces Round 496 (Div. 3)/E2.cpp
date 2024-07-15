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
    int n, m; cin >> n >> m;

    int64_t ans = 0;

    int cnt_pref_greater_eq[2 * n + 1] = {};
    int sum_greater_eq = n, cnt_greater_eq = 0;

    int cnt_pref_greater[2 * n + 1] = {};
    int sum_greater = n, cnt_greater = 0;

    cnt_pref_greater[n] = cnt_pref_greater_eq[n] = 1;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x >= m){
            cnt_greater_eq += cnt_pref_greater_eq[sum_greater_eq];
            sum_greater_eq++;
        } else {
            sum_greater_eq--;
            cnt_greater_eq -= cnt_pref_greater_eq[sum_greater_eq];
        }

        ans += cnt_greater_eq;
        cnt_pref_greater_eq[sum_greater_eq]++;

        if(x >= m + 1){
            cnt_greater += cnt_pref_greater[sum_greater];
            sum_greater++;
        } else {
            sum_greater--;
            cnt_greater -= cnt_pref_greater[sum_greater];
        }

        ans -= cnt_greater;
        cnt_pref_greater[sum_greater]++;
    }

    cout << ans << '\n';
}
