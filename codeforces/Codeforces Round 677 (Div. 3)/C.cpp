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
        int arr[n], maxi = INT_MIN;
        for(int &x : arr){
            cin >> x;
            maxi = max(maxi, x);
        }

        int ans = -1;
        for(int i = 0; i < n; ++i){
            if(arr[i] == maxi && ((i && arr[i - 1] != maxi) || (i + 1 < n && arr[i + 1] != maxi))){
                ans = i + 1;
                break;
            }
        }
        cout << ans << '\n';
    }
}
