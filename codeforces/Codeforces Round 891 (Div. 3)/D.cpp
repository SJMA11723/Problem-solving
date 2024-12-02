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
        int a[n];
        for(int &x : a) cin >> x;
        int maxi = INT_MIN, ans = 0;
        for(int i = 0; i < n; ++i){
            int b; cin >> b;
            a[i] -= b;
            if(a[i] == maxi) ans++;
            else if(a[i] > maxi){
                maxi = a[i];
                ans = 1;
            }
        }
        cout << ans << '\n';
        for(int i = 0; i < n; ++i)
            if(a[i] == maxi) cout << i + 1 << " \n"[!--ans];
    }
}
