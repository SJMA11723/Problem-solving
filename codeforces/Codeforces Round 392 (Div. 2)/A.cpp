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
    int maxi = 0, arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; ++i) ans += maxi - arr[i];
    cout << ans << '\n';
}
