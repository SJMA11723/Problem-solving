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
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;

    int idx1 = 0, idx2 = 0;
    while(idx1 < n || idx2 < m){
        if(idx2 == m || (idx1 < n && a[idx1] < b[idx2])) cout << a[idx1++] << ' ';
        else cout << b[idx2++] << ' ';
    }
    cout << '\n';
}
