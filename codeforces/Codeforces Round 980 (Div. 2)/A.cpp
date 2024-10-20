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
        int a, b; cin >> a >> b;
        if(b <= a) cout << a << '\n';
        else {
            int l = 0, r = a + 1;
            while(l < r){
                int mid = l + (r - l) / 2;
                if(a < b - mid) l = mid + 1;
                else r = mid;
            }
            cout << max(0, a - l) << '\n';
        }
    }
}
