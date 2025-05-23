/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++){
        if(i < r) z[i] = min(r - i, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

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
    vector<int> z = z_function(s);
    vector<int> pi = prefix_function(s);

    int max_len = 0, max_pos = -1;
    for(int i = 1; i + 1 < n; ++i){
        int len = z[i];
        if(len == n - i) len--;

        if(max_len < len){
            max_len = len;
            max_pos = i;
        }
    }

    int ans = pi[n - 1];
    while(ans > max_len) ans = pi[ans - 1];

    if(ans) cout << s.substr(0, ans) << '\n';
    else cout << "Just a legend\n";
}
