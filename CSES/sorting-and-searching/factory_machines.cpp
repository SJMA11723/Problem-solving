/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t products(int n, int machines[], const int64_t sec){
    int64_t res = 0;
    for(int i = 0; i < n; ++i) res += sec / machines[i];
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t; cin >> n >> t;
    int machines[n];
    for(int &x : machines) cin >> x;

    int64_t l = 0, r = LLONG_MAX / n;
    while(l < r){
        int64_t mid = l + (r - l) / 2;
        if(products(n, machines, mid) >= t) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}
