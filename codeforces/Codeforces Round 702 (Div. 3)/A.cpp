/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = 0;
        int prv; cin >> prv;
        for(int i = 1; i < n; ++i){
            int x; cin >> x;
            int mini = min(prv, x), maxi = max(prv, x);
            while(maxi > 2 * mini) ans++, mini <<= 1;
            prv = x;
        }
        cout << ans << '\n';
    }
}
