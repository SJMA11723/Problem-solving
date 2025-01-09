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
        int n, m; cin >> n >> m;
        int arr[n], last = -1;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            if(arr[i] != i + 1) last = i;
        }
        last++;

        long double ans = 0, prod = 1;

        while(m--){
            int r; cin >> r;
            long double p; cin >> p;
            if(r >= last){
                ans += prod * p;
                prod *= 1 - p;
            }
        }

        cout << fixed << setprecision(7);

        if(!last){
            cout << 1.0 << '\n';
            continue;
        }

        cout << ans << '\n';
    }
}
