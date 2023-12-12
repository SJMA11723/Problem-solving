/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long n){
    for(long long i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
        if(a - b == 1 && is_prime(a + b)) cout << "YES\n";
        else cout << "NO\n";
    }
}
