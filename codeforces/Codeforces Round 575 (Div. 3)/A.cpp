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
        int64_t a, b, c; cin >> a >> b >> c;
        if(max({a, b, c}) == a) swap(a, c);
        else if(max({a, b, c}) == b) swap(b, c);

        if(a < b){
            int64_t k = min(b - a, c);
            a += k;
            c -= k;
        } else {
            int64_t k = min(a - b, c);
            b += k;
            c -= k;
        }

        a += c / 2;
        b += c / 2;
        cout << min(a, b) << '\n';
    }
}
