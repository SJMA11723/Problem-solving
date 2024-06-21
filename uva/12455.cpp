/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, p; cin >> n >> p;
        int arr[p];
        for(int i = 0; i < p; ++i) cin >> arr[i];

        bool ok = false;
        int lim = 1 << p;
        for(int mask = 0; mask < lim; ++mask){
            int sum = 0;
            for(int i = 0; i < p; ++i)
                if(is_on(mask, i)) sum += arr[i];
            if(sum == n){
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
