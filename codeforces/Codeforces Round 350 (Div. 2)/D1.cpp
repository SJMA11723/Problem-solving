/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n, int a[], int b[], int k, int64_t x){
    int64_t need = 0;
    for(int i = 0; i < n; ++i) need += max(0ll, x * a[i] - b[i]);
    return need <= k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int a[n], b[n];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    int64_t l = 0, r = 2001;
    while(l < r){
        int64_t mid = l + (r - l) / 2;
        if(check(n, a, b, k, mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << '\n';
}
