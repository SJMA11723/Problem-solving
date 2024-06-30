/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n, int a[], int64_t x){
    int64_t supervisors = 0;
    for(int i = 0; i < n; ++i) supervisors += max(0ll, x - a[i]);
    return supervisors >= x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;

    int64_t l = *max_element(a, a + n), r = 1e14;
    while(l < r){
        int64_t mid = l + (r - l) / 2;
        if(check(n, a, mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}
