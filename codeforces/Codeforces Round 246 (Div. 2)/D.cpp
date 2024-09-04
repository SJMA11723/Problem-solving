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
    string s; cin >> s;
    int n = s.size();
    vector<int> pi = prefix_function(s);
    int cnt[n + 1] = {};
    for(int i = 0; i < n; ++i) cnt[pi[i]]++;
    for(int i = n - 1; 0 < i; --i) cnt[pi[i - 1]] += cnt[i];
    for(int i = 0; i <= n; ++i) cnt[i]++;

    vector<int> ans;
    ans.push_back(n);
    int len = pi[n - 1];
    while(len){
        if(cnt[len]) ans.push_back(len);
        len = pi[len - 1];
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ' << cnt[ans[i]] << '\n';
}
