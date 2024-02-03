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
        int64_t arr[3]; cin >> arr[0] >> arr[1] >> arr[2];
        cout << (arr[2] + arr[1] + arr[0]) / 2 << '\n';
    }
}
