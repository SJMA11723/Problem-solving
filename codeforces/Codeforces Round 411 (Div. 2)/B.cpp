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
    for(int i = 0; i < n / 2; ++i) cout << (i % 2 ? "aa" : "bb");
    if(n % 2) cout << (n / 2 % 2 ? 'a' : 'b') << '\n';
}
