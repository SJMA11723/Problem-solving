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
        int arr[n];
        for(int &x : arr) cin >> x;

        bool vis[n] = {};
        for(int k = 1; k <= n; ++k){
            int idx = -1;
            for(int i = 1; i < n; ++i){
                if(vis[i - 1]) continue;
                if(arr[i] != k) continue;
                idx = i;
                break;
            }

            if(idx == -1) continue;
            if(idx + 1 == k){
                //vis[idx] = true;
                continue;
            }

            //cout << k << ' ' << idx << '\n';

            for(int i = idx - 1; 0 <= i; --i){
                if(vis[i]) break;
                if(arr[i] < arr[i + 1]) break;
                //cout << i << ' ' << i + 1 << '\n';
                swap(arr[i], arr[i + 1]);
                vis[i] = true;
            }
        }

        for(int i = 0; i < n; ++i) cout << arr[i] << " \n"[i + 1 == n];
    }
}
