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
    int arr[n];
    int suff = 0, suff_o = 0;
    for(int &x : arr) cin >> x, suff += x;
    for(int i = 1; i < n; i += 2) suff_o += arr[i];

    int ans = 0, pref = 0, pref_o = 0;
    for(int i = 0; i < n; ++i){
        suff -= arr[i];
        if(i % 2) suff_o -= arr[i];

        ans += 2ll * (pref_o + suff - suff_o) == pref + suff;

        pref += arr[i];
        if(i % 2) pref_o += arr[i];
    }

    cout << ans << '\n';
}
