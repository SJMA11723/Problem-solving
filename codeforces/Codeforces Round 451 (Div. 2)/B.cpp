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
    long long n, a, b;
    cin >> n >> a >> b;
    for(long long i = 0; i <= n; ++i){
        if(n - i * a >= 0 && (n - i * a) % b == 0){
            cout << "YES\n" << i << ' ' << (n - i * a) / b << '\n';
            return 0;
        }

        if(n - i * b >= 0 && (n - i * b) % a == 0){
            cout << "YES\n" << (n - i * b) / a << ' ' << i << '\n';
            return 0;
        }
    }
    cout << "NO\n";
}
