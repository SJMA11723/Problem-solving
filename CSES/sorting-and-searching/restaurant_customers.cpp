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
    int n; cin >> n;
    pair<int, int> arr[2 * n];
    for(int i = 0; i < n; ++i){
        int a, b; cin >> a >> b;
        arr[i] = {a, 1};
        arr[i + n] = {b, 0};
    }
    sort(arr, arr + 2 * n);

    int pending = 0, ans = 0;
    for(int i = 0; i < 2 * n; ++i){
        if(arr[i].second) pending++;
        else pending--;
        ans = max(ans, pending);
    }
    cout << ans << '\n';
}
