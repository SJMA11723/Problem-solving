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
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        int l = 0, r = m;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(n * (1ll * m / (mid + 1) * mid + m % (mid + 1)) >= k) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
}
