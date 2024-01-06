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
        int n, q; cin >> n >> q;
        int64_t arr[n + 1]; arr[0] = 0;
        int maxi[n + 1]; maxi[0] = 0;
        for(int i = 1; i <= n; ++i){
            cin >> arr[i];
            maxi[i] = max(maxi[i - 1], (int)arr[i]);
            arr[i] += arr[i - 1];
        }

        while(q--){
            int k; cin >> k;
            int l = 1, r = n + 1;
            while(l < r){
                int mid = (l + r) / 2;
                if(k < maxi[mid]) r = mid;
                else l = mid + 1;
            }
            cout << arr[l - 1] << ' ';
        }
        cout << '\n';
    }
}
