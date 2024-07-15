
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
        int n, k; cin >> n >> k;
        if(n == 1) cout << "0\n";
        else if(n <= k) cout << "1\n";
        else if(k == 2) cout << n - 1 << '\n';
        else cout << n / (k - 1) + (n % (k - 1) != 1 && n % (k - 1) != 0)<< '\n';
    }
}
