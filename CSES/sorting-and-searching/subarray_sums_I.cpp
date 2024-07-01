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
    int n, x; cin >> n >> x;
    int arr[n];
    for(int &v : arr) cin >> v;

    int sum = 0, l = 0, ans = 0;
    for(int r = 0; r < n; ++r){
        sum += arr[r];
        while(sum > x) sum -= arr[l++];
        if(sum == x) ans++;
    }
    cout << ans << '\n';
}
