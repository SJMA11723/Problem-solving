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
        int arr[2 * n], ans[n];
        int idx1 = 0, idx2 = 0;
        for(int i = 0; i < 2 * n; ++i){
            int x; cin >> x;
            if(idx1 == idx2) ans[idx1++] = x;
            else {
                if(ans[idx2] == x) idx2++;
                else ans[idx1++] = x;
            }
        }

        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}
