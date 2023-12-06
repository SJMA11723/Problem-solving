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
        long long n; cin >> n;
        for(int i = 1; i <= n + 1; ++i){
            if(n % i){
                cout << i - 1 << '\n';
                break;
            }
        }
    }
}
