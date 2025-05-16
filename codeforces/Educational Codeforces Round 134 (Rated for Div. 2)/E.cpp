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

void compute_automaton(const string &s, vector<vector<int>> &aut, vector<int> &pi){
    int n = s.size();
    aut.assign(n, vector<int>(26));
    for(int i = 0; i < n; ++i){
        for(int c = 0; c < 26; ++c){
            if(i && 'a' + c != s[i]) aut[i][c] = aut[ pi[i - 1] ][c];
            else aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    vector<int> pi = prefix_function(s);
    vector<vector<int>> aut;
    compute_automaton(s, aut, pi);

    int q; cin >> q;
    while(q--){
        string t; cin >> t;
        int m = t.size();
        s += t;
        for(int i = 0; i < m; ++i){
            int j = pi.back();

            bool ok = true;
            while(j && t[i] != s[j]){
                if(j < n){
                    j = aut[j][t[i] - 'a'];
                    ok = false;
                    break;
                } else j = pi[j - 1];
            }

            pi.push_back(j + (t[i] == s[j] && ok));
            cout << pi.back() << " \n"[i + 1 == m];
        }
        while(m--) s.pop_back(), pi.pop_back();
    }
}
