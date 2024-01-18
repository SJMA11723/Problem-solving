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
    int n; cin >> n;
    if(n % 2) cout << "-1\n";
    else {
        for(int i = 2; i <= n; i += 2) cout << i << ' ' << i - 1 << ' ';
        cout << '\n';
    }
}
