/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t count_smaller(const int n, int a[], int b[], const int64_t x){
    int64_t res = 0;
    for(int i = 0; i < n; ++i){
        if(x < a[i]) continue;
        res += min(1ll*b[i], x - 1) - 1ll*a[i] + 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int a[n], b[n];
    for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    int64_t l = -2e9, r = 2e9 + 1;
    while(l < r){
        int64_t mid = l + (r - l) / 2;
        if(count_smaller(n, a, b, mid) > k) r = mid;
        else l = mid + 1;
    }
    cout << l - 1 << '\n';
}
