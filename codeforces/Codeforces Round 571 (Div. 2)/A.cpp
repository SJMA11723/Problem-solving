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
    int a, b, c; cin >> a >> b >> c;
    if(a <= min(b, c)) cout << "Yes\n";
    else cout << "No\n";
}