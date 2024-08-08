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
    int n, m, k; cin >> n >> m >> k;
    int arr[n];
    for(int &x : arr) cin >> x;

    int l[m], r[m], d[m];
    for(int i = 0; i < m; ++i) cin >> l[i] >> r[i] >> d[i], l[i]--, r[i]--;

    int acc_op[m + 1] = {};
    for(int i = 0; i < k; ++i){
        int x, y; cin >> x >> y;
        x--, y--;
        acc_op[x]++;
        acc_op[y + 1]--;
    }

    int64_t acc_arr[n + 1] = {}, sum = 0;
    for(int i = 0; i < m; ++i){
        sum += acc_op[i];
        acc_arr[l[i]] += sum * d[i];
        acc_arr[r[i] + 1] -= sum * d[i];
    }

    sum = 0;
    for(int i = 0; i < n; ++i){
        sum += acc_arr[i];
        cout << sum + arr[i] << " \n"[i + 1 == n];
    }
}
