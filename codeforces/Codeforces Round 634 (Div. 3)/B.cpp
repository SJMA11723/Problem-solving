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
        int n, a, b; cin >> n >> a >> b;
        string str;
        for(int i = 0; i < b; ++i) str += char('a' + i);
        while(str.size() < a) str += str.back();

        for(int i = 0; i < n; ++i) cout << str[i % a];
        cout << '\n';
    }
}
