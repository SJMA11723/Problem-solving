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
    int q; cin >> q;
    while(q--){
        int k, n, a, b;
        cin >> k >> n >> a >> b;
        int l = 0, r = n + 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(1ll * a * mid + 1ll * (n - mid) * b < k) l = mid + 1;
            else r = mid;
        }
        cout << l - 1 << '\n';
    }
}
