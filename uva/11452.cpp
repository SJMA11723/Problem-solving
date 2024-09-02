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
        string s; cin  >> s;
        int n = s.size();
        vector<int> pi = prefix_function(s);
        int j = pi.back();
        while(j && 3 * (n - j) <= n) j = pi[j - 1];
        int p = n - j;
        int idx = n % p;
        for(int i = 0; i < 8; ++i) cout << s[(idx + i) % p];
        cout << "...\n";
    }
}
