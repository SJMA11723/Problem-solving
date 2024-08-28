/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(const string &s){
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) j = pi[j - 1];
        pi[i] = j + (s[i] == s[j]);
    }
    return pi;
}

int count_occurrences(string &s, const string &t){
    s += "#";
    vector<int> pi = prefix_function(s);
    s.pop_back();

    int res = 0, prev = 0;
    for(int i = 0; i < t.size(); ++i){
        int j = prev;
        while(j && t[i] != s[j]) j = pi[j - 1];
        if(t[i] == s[j]) j++;
        prev = j;
        if(j == s.size()) res++;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string t, s; cin >> t >> s;
    cout << count_occurrences(s, t) << '\n';
}
