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
    int ans = n;
    for(int i = 1; i < n; ++i){
        int x; cin >> x;
        ans ^= x ^ i;
    }
    cout << ans << '\n';
}
