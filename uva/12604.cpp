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

int match(const vector<int> &pi, const string &s, const string &t){
    int prv = 0, res = 0;
    for(int i = 0; i < t.size(); ++i){
        int j = prv;
        while(j && t[i] != s[j]) j = pi[j - 1];
        prv = j + (s[j] == t[i]);
        if(prv == s.size()) res++;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string A, W, S;
        cin >> A >> W >> S;

        int pos[300] = {};
        for(int i = 0; i < A.size(); ++i) pos[A[i]] = i;

        vector<int> ans;
        for(int i = 0; i < A.size(); ++i){
            string w;
            for(char c : W) w += A[(pos[c] + i) % A.size()];

            vector<int> pi = prefix_function(w);

            if(match(pi, w, S) == 1) ans.push_back(i);
        }

        if(ans.empty()) cout << "no solution\n";
        else if(ans.size() == 1) cout << "unique: " << ans[0] << '\n';
        else {
            cout << "ambiguous: ";
            for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i + 1 == ans.size()];
        }
    }
}
