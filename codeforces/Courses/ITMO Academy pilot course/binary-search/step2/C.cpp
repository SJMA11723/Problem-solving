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
    int n, x, y; cin >> n >> x >> y;
    int l = 0, r = 10 * n;
    while(l < r){
        int mid = l + (r - l) / 2;
        if( (mid / x) + (mid / y) >= n - 1) r = mid;
        else l = mid + 1;
    }
    cout << l + min(x, y) << '\n';
}
