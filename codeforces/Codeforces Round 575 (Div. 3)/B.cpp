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
        int n, k; cin >> n >> k;
        int cnt_odd = 0;
        int arr[n];
        for(int &x : arr){
            cin >> x;
            cnt_odd += x % 2;
        }
        if(cnt_odd < k || (cnt_odd - k) % 2) cout << "NO\n";
        else {
            cout << "YES\n";
            for(int i = 0; i < n; ++i){
                if(k > 1 && arr[i] % 2){
                    k--;
                    cout << i + 1 << ' ';
                }
            }
            cout << n << '\n';
        }
    }
}
