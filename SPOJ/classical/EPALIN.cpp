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
        while(j && s[j] != s[i]) j = pi[j - 1];
        pi[i] = j + (s[i] == s[j]);
    }
    return pi;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(cin >> s){
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<int> pi = prefix_function(rev);
        int j = 0;
        for(int i = 0; i < n; ++i){
            while(j && s[i] != rev[j]) j = pi[j - 1];
            j += s[i] == rev[j];
        }

        cout << s + rev.substr(j) << '\n';
    }
}
