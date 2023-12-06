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
        long long n;
        cin >> n;
        if(n < 4 || n % 2){
            cout << "-1\n";
            continue;
        }
        n /= 2;
        cout << n / 3 + (n % 3 != 0) << ' ' << n / 2 << '\n';
    }
}
