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
    int arr[5];
    for(int i = 1; i < 5; ++i) cin >> arr[i];
    string s; cin >> s;
    int ans = 0;
    for(char c : s) ans += arr[c - '0'];
    cout << ans << '\n';
}
