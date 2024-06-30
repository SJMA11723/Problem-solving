/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t count_smaller(const int64_t n, const int64_t x){
    int64_t res = 0;
    for(int64_t i = 1; i <= n; ++i) res += min(n, (x + i - 1) / i - 1);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n; cin >> n;
    int64_t k = (n * n + 1) / 2;

    int64_t l = (n + 1) / 2, r = (n * n + 2) / 3 + 1;
    //int64_t l = 1, r = (n * n + 1);
    while(l < r){
        int64_t mid = l + (r - l) / 2;
        if(count_smaller(n, mid) >= k) r = mid;
        else l = mid + 1;
    }
    cout << l - 1 << '\n';
}
