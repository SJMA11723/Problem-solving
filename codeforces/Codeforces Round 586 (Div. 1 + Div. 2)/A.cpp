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
    int cnt[26] = {};
    for(int i = 0; i < n; ++i){
        char c; cin >> c;
        cnt[c - 'a']++;
    }
    while(cnt['n' - 'a']--) cout << "1 ";
    while(cnt['z' - 'a']--) cout << "0 ";
    cout << '\n';
}