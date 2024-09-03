/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(const vector<int> &s){
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
    int n, w; cin >> n >> w;
    int prv; cin >> prv;
    vector<int> p, t;
    for(int i = 1; i < n; ++i){
        int x; cin >> x;
        t.push_back(x - prv);
        prv = x;
    }

    cin >> prv;
    for(int i = 1; i < w; ++i){
        int x; cin >> x;
        p.push_back(x - prv);
        prv = x;
    }

    if(w == 1){
        cout << n << '\n';
        return 0;
    }

    p.push_back(INT_MAX);
    vector<int> pi = prefix_function(p);
    int ans = 0;
    prv = 0;
    for(int i = 0; i < t.size(); ++i){
        int j = prv;
        while(j && t[i] != p[j]) j = pi[j - 1];
        prv = j + (t[i] == p[j]);
        if(prv == w - 1) ans++;
    }
    cout << ans << '\n';
}
