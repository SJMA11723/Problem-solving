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
        int a, b, k; cin >> a >> b >> k;
        int boys[k], girls[k];
        for(int &x : boys) cin >> x, x--;
        for(int &x : girls) cin >> x, x--;

        int64_t ans = 0;
        int pairs_b[max(a, b)] = {};
        int pairs_g[max(a, b)] = {};
        for(int i = 0; i < k; ++i){
            ans += i - pairs_b[ boys[i] ] - pairs_g[ girls[i] ];
            pairs_b[boys[i]]++;
            pairs_g[girls[i]]++;
        }
        cout << ans << '\n';
    }
}
