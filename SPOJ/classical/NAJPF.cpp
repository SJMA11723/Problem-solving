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
        pi[i] =  + (s[i] == s[j]);
    }
    return pi;
}

vector<int> match(const string &p, const string &t){
    vector<int> res;
    vector<int> pi = prefix_function(p);
    int prv = 0;
    for(int i = 0; i < t.size(); ++i){
        int j = prv;
        while(j && t[i] != p[j]) j = pi[j - 1];
        prv = j + (p[j] == t[i]);
        if(prv == p.size() - 1) res.push_back(i + 2 - prv);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string A, B;
        cin >> A >> B;
        B += "#";
        vector<int> occur = match(B, A);
        if(occur.empty()) cout << "Not Found\n";
        else {
            cout << occur.size() << '\n';
            for(int i = 0; i < occur.size(); ++i) cout << occur[i] << " \n"[i + 1 == occur.size()];
        }
        cout << '\n';
    }
}
