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
    int m; cin >> m;
    int arr[m];
    for(int &x : arr) cin >> x;
    sort(arr, arr + m);
    bool ok = true;
    for(int i = 0; i < m; ++i) ok = ok && arr[i] % arr[0] == 0;

    if(!ok){
        cout << "-1\n";
        return 0;
    }

    cout << 2 * m << '\n';
    for(int i = 0; i < m; ++i) cout << arr[i] << ' ' << arr[0] << " \n"[i + 1 == m];
}
