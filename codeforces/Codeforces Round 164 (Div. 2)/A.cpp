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
    int h[n], a[n], ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> h[i] >> a[i];
        for(int j = 0; j < i; ++j) ans += (h[i] == a[j]) + (h[j] == a[i]);
    }
    cout << ans << '\n';
}
