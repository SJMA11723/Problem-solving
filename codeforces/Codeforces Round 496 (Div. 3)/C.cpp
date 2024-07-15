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
    map<int, int> cub;
    int a[n];
    for(int &x : a){
        cin >> x;
        cub[x]++;
    }

    bool good[n] = {};
    for(int k = 0; k <= 30; ++k)
        for(int i = 0; i < n; ++i)
            if((1 << k) >= a[i] && cub[(1 << k) - a[i]] - (2*a[i] == (1 << k))) good[i] = true;

    int ans = 0;
    for(int i = 0; i < n; ++i) ans += !good[i];
    cout << ans << '\n';
}
