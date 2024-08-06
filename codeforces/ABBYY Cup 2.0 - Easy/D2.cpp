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
    int n, m, c; cin >> n >> m >> c;
    int a[n], b[m];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    int acc[n] = {};
    for(int i = 0; i < m; ++i){
        acc[i] += b[i];
        acc[n - m + i + 1] -= b[i];
    }

    //for(int i = 0; i < n; ++i) cout << acc[i] << ' '; cout << '\n';

    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += acc[i];
        cout << (a[i] + sum) % c << " \n"[i + 1 == n];
    }
}
