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
    int64_t H; cin >> H;
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    int64_t sum = 0, mini = LLONG_MAX;
    for(int i = 0; i < n; ++i){
        sum += arr[i];
        mini = min(mini, sum);

        if(H + sum <= 0){
            cout << i + 1 << '\n';
            return 0;
        }
    }

    if(sum >= 0){
        cout << "-1\n";
        return 0;
    }

    sum = -sum;
    int64_t ans = LLONG_MAX, sum2 = 0;
    for(int i = 0; i < n; ++i){
        sum2 += arr[i];
        ans = min(ans, (H + sum2 + sum - 1) / sum * n + i + 1);
    }

    cout << ans << '\n';
}
