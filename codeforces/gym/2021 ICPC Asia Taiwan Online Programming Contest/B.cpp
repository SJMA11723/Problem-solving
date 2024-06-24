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
        int64_t sum = -n;
        for(int i = 1; i * i <= n; ++i){
            if(n % i) continue;
            sum += i;
            if(i * i != n) sum += n / i;
        }
        if(sum < n) cout << "deficient\n";
        else if(sum == n) cout << "perfect\n";
        else cout << "abundant\n";
    }
}
