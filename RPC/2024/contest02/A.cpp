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
    int n, m, k;
    cin >> n >> m >> k;
    int64_t arr[n], sum = 0, sum2 = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + n, greater<int64_t>());
    for(int i = 0; i < min(m + k, n); ++i) sum2 += arr[i];

    cout << fixed << setprecision(10) << (long double)(sum2) / sum * 100 << '\n';
}
