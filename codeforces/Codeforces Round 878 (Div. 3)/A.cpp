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
        string s; cin >> s;
        char last = s[0];
        cout << last;
        for(int i = 1; i < n; ++i){
            if(s[i] == last){
                last = -1;
            } else if(last == -1){
                last = s[i];
                cout << last;
            }
        }
        cout << '\n';
    }
}
