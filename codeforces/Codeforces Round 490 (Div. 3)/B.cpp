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
    string s; cin >> s;
    for(int i = 1; i <= n; ++i){
        if(n % i) continue;
        reverse(s.begin(), s.begin() + i);
    }
    cout << s << '\n';
}
