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
        int64_t p, a, b, c;
        cin >> p >> a >> b >> c;
        cout << min({(p + a - 1) / a * a, (p + b - 1) / b * b, (p + c - 1) / c * c}) - p << '\n';
    }
}
