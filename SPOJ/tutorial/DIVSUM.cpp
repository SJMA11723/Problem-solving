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
        int n; cin >> n;
        if(n == 1){
            cout << "0\n";
            continue;
        }

        int64_t sum = 1;
        for(int i = 2; i * i <= n; ++i){
            if(n % i) continue;
            sum += i;
            if(i * i != n) sum += n / i;
        }
        cout << sum << '\n';
    }
}
