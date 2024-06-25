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
    int n, q; cin >> n >> q;
    int64_t arr[n + 1];
    arr[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << arr[b] - arr[a - 1] << '\n';
    }
}
