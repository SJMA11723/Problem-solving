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
    int n; cin >> n;
    int all_xor = 0;
    int arr[n];
    for(int &x : arr){
        cin >> x;
        all_xor ^= x;
    }

    for(int i = 0; i < n; ++i) cout << (arr[i] ^ all_xor) << " \n"[i + 1 == n];
}
