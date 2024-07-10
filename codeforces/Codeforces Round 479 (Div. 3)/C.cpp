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
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;
    sort(a, a + n);

    int l = 1, r = 1e9 + 1;
    while(l < r){
        int mid = l + (r - l) / 2;
        int smaller = upper_bound(a, a + n, mid) - a;
        if(smaller >= k) r = mid;
        else l = mid + 1;
    }

    if(upper_bound(a, a + n, l) - a == k) cout << l << '\n';
    else cout << "-1\n";
}
