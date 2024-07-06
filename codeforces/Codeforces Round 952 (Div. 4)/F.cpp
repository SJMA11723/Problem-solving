/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n, int a[], int c[], int h, uint64_t turns){
    uint64_t attack = 0;
    for(int i = 0; i < n; ++i) attack += (turns + c[i] - 1) / c[i] * a[i];
    return attack >= h;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int h, n; cin >> h >> n;
        int a[n], c[n];
        for(int &x : a) cin >> x;
        for(int &x : c) cin >> x;

        uint64_t l = 0, r = 5e10;
        while(l < r){
            uint64_t mid = l + (r - l) / 2;
            if(check(n, a, c, h, mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
}
