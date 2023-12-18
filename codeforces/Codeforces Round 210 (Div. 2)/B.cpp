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
    int n, k; cin >> n >> k;
    if(k == n) cout << "-1\n";
    else {
        int no_good = n - k;
        cout << n - k << ' ';
        for(int i = 1; i < n - k; ++i) cout << i << ' ';
        for(int i = n - k + 1; i <= n; ++i) cout << i << ' ';
        cout << '\n';
    }
}
