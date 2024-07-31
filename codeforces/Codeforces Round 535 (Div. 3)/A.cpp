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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(make_pair(a, b) < make_pair(c, d)) cout << a << ' ' << d << '\n';
        else cout << b << ' ' << c << '\n';
    }
}
