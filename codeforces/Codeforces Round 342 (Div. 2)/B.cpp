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
    string t, p; cin >> t >> p;
    int n = p.size();
    p += "#";

    vector<int> pi = prefix_function(p);

    vector<int> occur;
    int prv = 0;
    for(int i = 0; i < t.size(); ++i){
        int j = prv;
        while(j && p[j] != t[i]) j = pi[j - 1];
        prv = j + (p[j] == t[i]);
        if(prv == n) occur.push_back(i - n + 1);
    }

    int ans = 0;
    int last = -1;
    for(int i = 0; i < occur.size(); ++i){
        if(occur[i] <= last) continue;
        ans++;
        last = occur[i] + n - 1;
    }

    cout << ans << '\n';
}
