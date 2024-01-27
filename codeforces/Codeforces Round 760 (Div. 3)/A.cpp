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
        int arr[7];
        for(int i = 0; i < 7; ++i) cin >> arr[i];
        cout << arr[0] << ' ' << arr[1] << ' ' << arr[6] - arr[0] - arr[1] << '\n';
    }
}
