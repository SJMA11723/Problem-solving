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
    int a[n];
    for(int &x : a) cin >> x;

    int zero = 0;
    map<pair<int, int>, int> cub;
    for(int i = 0; i < n; ++i){
        int b; cin >> b;
        if(a[i]){
            int g = __gcd(abs(b), abs(a[i]));
            if(a[i] < 0) cub[{b / g, -a[i] / g}]++;
            else cub[{-b / g, a[i] / g}]++;
        } else if(!b) zero++;
    }

    int ans = zero;
    for(auto [p, cnt] : cub) ans = max(ans, cnt + zero);
    cout << ans << '\n';
}
