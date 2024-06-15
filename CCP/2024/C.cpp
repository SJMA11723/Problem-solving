/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int arr[], int n, int d, int m){
    m--;
    int ant = arr[0];
    for(int i = 1; i < n; ++i){
        if(abs(arr[i] - ant) >= d){
            ant = arr[i];
            m--;
        }
    }

    return m > 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];
    int m; cin >> m;
    sort(arr, arr + n);

    int l = 0, r = 1e9;
    while(l < r){
        int mid = (l + r) >> 1;
        //cout << l << ' ' << r << ' ' << mid << '\n';
        if(check(arr, n, mid, m)) r = mid;
        else l = mid + 1;
    }

    cout << l - 1 << '\n';
}
