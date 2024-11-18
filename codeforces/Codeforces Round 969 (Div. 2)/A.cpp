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
        int l, r; cin >> l >> r;
        if(l % 2 == 0) l++;
        cout << (r - l + 1) / 4 + ((r - l + 1) % 4 == 3) << '\n';
    }
}
