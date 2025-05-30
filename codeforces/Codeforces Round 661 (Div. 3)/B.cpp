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
        int a[n], b[n], min_a = INT_MAX, min_b = INT_MAX;
        for(int &x : a) cin >> x, min_a = min(min_a, x);
        for(int &x : b) cin >> x, min_b = min(min_b, x);

        int64_t ans = 0;
        for(int i = 0; i <n ; ++i) ans += max(a[i] - min_a, b[i] - min_b);
        cout << ans << '\n';
    }
}
