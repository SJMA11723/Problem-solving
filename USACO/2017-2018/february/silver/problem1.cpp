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

    ifstream cin("reststops.in");
    ofstream cout("reststops.out");

    int L, n, rf, rb, ant = 0;
    cin >> L >> n >> rf >> rb;
    pair<int, int> arr[n];
    for(int i = 0; i < n; ++i){
        int x, c; cin >> x >> c;
        arr[i] = {c, x};
    }
    sort(arr, arr + n, greater<pair<int, int>>());

    int64_t ans = 0;
    int last = 0;
    for(int i = 0; i < n; ++i){
        int64_t x, c;
        tie(c, x) = arr[i];
        if(x < last) continue;
        ans += c * (x - last) * (rf - rb);
        last = x;
    }

    cout << ans << '\n';
}
