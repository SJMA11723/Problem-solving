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
        int cub[10] = {};
        int a, b, c; cin >> a >> b >> c;
        cub[a]++;
        cub[b]++;
        cub[c]++;
        if(cub[a] == 1) cout << a << '\n';
        else if(cub[b] == 1) cout << b << '\n';
        else cout << c << '\n';
    }
}
