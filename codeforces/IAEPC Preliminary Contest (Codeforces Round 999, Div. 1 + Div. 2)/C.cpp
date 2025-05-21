/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

#define MAXN 200000

using namespace std;

const int MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int &x : arr) cin >> x;

        int ans = arr[0] == 0, prv1 = 1, prv2 = 0;
        for(int i = 1; i < n; ++i){
            prv2 = prv1;
            prv1 = ans;
            ans = 0;
            if(arr[i - 1] == arr[i]) ans += prv1;
            if( (0 <= i - 2 && arr[i - 2] + 1 == arr[i]) || (i - 2 < 0 && arr[i] == 1) ) ans += prv2;
            if(ans >= MOD) ans -= MOD;
        }
        ans += prv1;
        if(ans >= MOD) ans -= MOD;
        cout << ans << '\n';
    }
}
