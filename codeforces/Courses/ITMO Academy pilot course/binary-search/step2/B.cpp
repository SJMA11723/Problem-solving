/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define EPS 1e-6

using namespace std;

int64_t pieces(int n, int arr[], long double t_size){
    int64_t res = 0;
    for(int i = 0; i < n; ++i) res += arr[i] / t_size;
    //cout << t_size << ' ' << res << '\n';
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int arr[n];
    for(int x : arr);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    long double l = 0, r = INT_MAX;
    while(r - l > EPS){
        long double mid = (r - l)/ 2 + l;
        if(pieces(n, arr, mid) < k) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(7) << l << '\n';
}
