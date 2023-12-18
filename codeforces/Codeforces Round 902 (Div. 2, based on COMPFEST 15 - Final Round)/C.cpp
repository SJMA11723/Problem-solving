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
        int n, m, k;
        cin >> n >> m >> k;
        if(k > 3) cout << "0\n";
        else if(k == 1) cout << "1\n";
        else if(k == 2) cout << (m <= n ? m : n + m / n - 1) << '\n';
        else cout << max(0, m - m / n - n + 1) << '\n';
    }
}
