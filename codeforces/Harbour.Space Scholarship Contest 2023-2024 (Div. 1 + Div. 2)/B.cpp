/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        if(k % 2){
            vector<char> odd, even;
            for(int i = 0; i < n; ++i)
            if(i % 2) odd.push_back(s[i]);
            else even.push_back(s[i]);

            sort(all(odd), greater<char>());
            sort(all(even), greater<char>());

            for(int i = 0; i < n; ++i)
            if(i % 2) cout << odd.back(), odd.pop_back();
            else cout << even.back(), even.pop_back();
            cout << '\n';
        } else {
            sort(all(s));
            cout << s << '\n';
        }
    }
}
