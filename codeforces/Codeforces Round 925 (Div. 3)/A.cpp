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
        int n; cin >> n;
        for(int i = 0; i < 26; ++i)
        for(int j = 0; j < 26; ++j)
        for(int k = 0; k < 26; ++k)
        if(i + j + k + 3 == n){
            cout << char(i + 'a') << char(j + 'a') << char(k + 'a') << '\n';
            i = j = k = 30;
        }
    }
}
