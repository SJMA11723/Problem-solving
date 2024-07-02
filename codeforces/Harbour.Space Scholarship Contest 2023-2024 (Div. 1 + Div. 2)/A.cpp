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
    int t; cin >> t;
    while(t--){
        int x, y, n; cin >> x >> y >> n;
        int arr[n];
        arr[n - 1] = y;
        for(int i = n - 2; 0 <= i; --i) arr[i] = arr[i + 1] + i - n + 1;
        if(arr[0] >= x){
            arr[0] = x;
            for(int i = 0; i < n; ++i) cout << arr[i] << " \n"[i + 1 == n];
        } else cout << "-1\n";
    }
}
