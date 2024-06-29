/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define EPS 1e-6

using namespace std;

bool check(const int n, int arr[], const long double x, const int d){
    long double pref[n];
    //cout << "Mean: " << x << '\n';
    pref[0] = arr[0] - x;
    //cout << pref[0] << ' ';
    for(int i = 1; i < n; ++i) pref[i] = pref[i - 1] + arr[i] - x;
    //cout << '\n';

    if(0 <= pref[d - 1]) return true;

    long double mini = numeric_limits<long double>::max();
    for(int i = d; i < n; ++i){
        mini = min(mini, pref[i - d]);
        //cout << i << ' ' << pref[i] << ' ' << mini << '\n';
        if(mini <= pref[i] || 0 <= pref[i]) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d; cin >> n >> d;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];

    long double l = 0, r = 101;
    for(int k = 0; k < 100; ++k){
        long double mid = l + (r - l) / 2;
        //cout << "Interval: " << l << ' ' << r << '\n';
        if(check(n, arr, mid, d)) l = mid;
        else r = mid;
    }

    //cout << "ANS MEAN: " << l << '\n';

    long double pref[n];
    pref[0] = arr[0] - l;
    for(int i = 1; i < n; ++i) pref[i] = pref[i - 1] + arr[i] - l;

    if(0 <= pref[d - 1]){
        cout << "1 " << d << '\n';
        return 0;
    }
    long double mini = numeric_limits<long double>::max();
    int idx = -1;
    for(int i = d; i < n; ++i){
        if(pref[i - d] < mini){
            idx = i - d + 1;
            mini = pref[i - d];
        }
        if(mini <= pref[i]){
            cout << idx + 1 << ' ' << i + 1 << '\n';
            break;
        }

        if(0 <= pref[i]){
            cout << 1 << ' ' << i + 1 << '\n';
            break;
        }
    }
}
