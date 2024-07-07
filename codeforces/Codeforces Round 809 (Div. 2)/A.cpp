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
        int a[n];
        for(int &x : a) cin >> x, x--;
        string ans(m, 'B');

        for(int &x : a){
            int mini = min(x, m - 1 - x);
            int maxi = max(x, m - 1 - x);

            if(ans[mini] == 'A') ans[maxi] = 'A';
            else ans[mini] = 'A';
        }

        cout << ans << '\n';
    }
}
