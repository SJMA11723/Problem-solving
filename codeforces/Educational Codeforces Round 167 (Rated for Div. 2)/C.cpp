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
        int r1 = 0, r2 = 0;
        int a[n], b[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];

        for(int i = 0; i < n; ++i){
            if(a[i] == b[i]) continue;
            else if(a[i] < b[i]) r2 += b[i];
            else r1 += a[i];
        }

        for(int i = 0; i < n; ++i){
            if(a[i] == b[i] && a[i] == 1){
                if(r1 < r2) r1++;
                else r2++;
            }
        }

        for(int i = 0; i < n; ++i){
            if(a[i] == b[i] && a[i] == -1){
                if(r1 < r2) r2--;
                else r1--;
            }
        }

        cout << min(r1, r2) << '\n';
    }
}
