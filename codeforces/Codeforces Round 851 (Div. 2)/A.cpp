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
        int arr[n], cnt_l = 0, cnt_r = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            if(arr[i] == 2) cnt_r++;
        }

        int ans = -1;
        for(int i = 0; i < n; ++i){
            if(arr[i] == 2){
                cnt_r--;
                cnt_l++;
            }

            if(cnt_l == cnt_r){
                ans = i + 1;
                break;
            }
        }

        cout << ans << '\n';
    }
}
