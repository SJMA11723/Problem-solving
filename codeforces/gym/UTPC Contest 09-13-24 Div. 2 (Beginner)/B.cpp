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
    int n, k; cin >> n >> k;
    int l = 0, cnt = 0, ans = 0;
    char arr[n];
    for(int r = 0; r < n; ++r){
        cin >> arr[r];
        if(arr[r] == '2') cnt++;
        while(cnt > k){
            if(arr[l] == '2') cnt--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
}
