/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int64_t count_smaller(int n, int a[], int b[], const int x){
    int64_t res = 0;
    for(int i = 0; i < n; ++i){
        int l = 0, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(a[i] + b[mid] >= x) r = mid;
            else l = mid + 1;
        }
        res += l;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n, k; cin >> n >> k;
    int a[n], b[n];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    sort(b, b + n);

    int l = 0, r = 2e9 + 1;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(count_smaller(n, a, b, mid) >= k) r = mid;
        else l = mid + 1;
    }
    cout << l - 1 << '\n';
}
