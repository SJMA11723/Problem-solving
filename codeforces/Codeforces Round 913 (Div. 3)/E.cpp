/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int64_t ans = 1;
        while(n){
            int d = n % 10;
            n /= 10;
            ans *= (d + 1) * (d + 2) / 2;
        }
        cout << ans << '\n';
    }
}
