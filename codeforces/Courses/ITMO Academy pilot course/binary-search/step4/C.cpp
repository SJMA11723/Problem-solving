/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define EPS 1e-6

using namespace std;

bool check(const int n, pair<int, int> arr[], const int k, const long double mean){
    long double T[n];
    for(int i = 0; i < n; ++i) T[i] = arr[i].first - mean * arr[i].second;
    sort(T, T + n, greater<long double>());

    long double sum = 0;
    for(int i = 0; i < k; ++i) sum += T[i];

    return sum >= 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    pair<int, int> arr[n];
    for(pair<int, int> &p : arr) cin >> p.first >> p.second;

    long double l = 0, r = 1e5;
    for(int i = 0; i < 37; ++i){
        long double mid = l + (r - l) / 2;
        if(check(n, arr, k, mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(7) << l << '\n';
}
