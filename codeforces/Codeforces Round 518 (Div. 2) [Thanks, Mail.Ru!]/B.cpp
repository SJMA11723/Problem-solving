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
    long long b; cin >> b;
    int ans = 0;
    for(long long i = 1; i * i <= b; ++i){
        if(b % i == 0){
            ans++;
            if(i * i != b) ans++;
        }
    }
    cout << ans << '\n';
}
