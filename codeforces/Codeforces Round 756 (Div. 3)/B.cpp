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
        int l = 0, r = a + b + 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(mid <= a && mid <= b && (a + b - 2 * mid) / 2 >= mid) l = mid + 1;
            else r = mid;
        }
        cout << l - 1 << '\n';
    }
}
