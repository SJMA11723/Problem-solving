/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i) cin >> arr[i];

    int lim = 1 << n;
    for(int mask = 0; mask < lim; ++mask){
        int sum = 0;
        for(int i = 0; i < n; ++i) sum += arr[i] * (is_on(mask, i) ? 1 : -1);
        if(sum % 360 == 0){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
