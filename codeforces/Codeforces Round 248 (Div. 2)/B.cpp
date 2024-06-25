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
    int64_t arr[n + 1], sorted_arr[n + 1];
    arr[0] = sorted_arr[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        sorted_arr[i] = arr[i];
        arr[i] += arr[i - 1];
    }
    sort(sorted_arr + 1, sorted_arr + n + 1);
    for(int i = 1; i <= n; ++i) sorted_arr[i] += sorted_arr[i - 1];

    int m; cin >> m;
    while(m--){
        int c, a, b;
        cin >> c >> a >> b;
        if(c == 1) cout << arr[b] - arr[a - 1] << '\n';
        else cout << sorted_arr[b] - sorted_arr[a - 1] << '\n';
    }
}
