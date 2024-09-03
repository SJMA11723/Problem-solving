/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(const string &s){
    int n = s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; ++i){
        int j = pi[i - 1];
        while(j && s[i] != s[j]) j = pi[j - 1];
        pi[i] = j + (s[i] == s[j]);
    }
    return pi;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        vector<int> pi = prefix_function(s);
        int prv = 0, ans_len = 0;
        int n = s.size();
        for(int i = n - 1; 0 <= i; --i){
            int j = prv;
            while(j && s[i] != s[j]) j = pi[j - 1];
            prv = j + (s[i] == s[j]);
            ans_len = max(ans_len, prv);
        }
        string ans = s.substr(0, ans_len);
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
}
