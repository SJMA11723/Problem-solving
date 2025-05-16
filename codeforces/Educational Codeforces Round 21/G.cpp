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

void compute_automaton(const string &s, vector<vector<int>> &aut){
    int n = s.size();
    vector<int> pi = prefix_function(s);
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
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    t += "#";
    vector<vector<int>> aut;
    compute_automaton(t, aut);

    int dp[n][m + 1];
    memset(dp, 0, sizeof(dp));

    for(int j = 0; j <= m; ++j){
        if(s[n - 1] == '?')
            for(int c = 0; c < 26; ++c) dp[n - 1][j] = max(dp[n - 1][j], aut[j][c] == m ? 1 : 0);
        else dp[n - 1][j] = aut[j][ s[n - 1] - 'a' ] == m;
    }

    for(int i = n - 2; 0 <= i; --i){
        for(int j = 0; j <= m; ++j){
            if(s[i] == '?')
                for(int c = 0; c < 26; ++c) dp[i][j] = max(dp[i][j], dp[i + 1][ aut[j][c] ] + (aut[j][c] == m) );
            else dp[i][j] = dp[i + 1][ aut[j][ s[i] - 'a' ] ] + (aut[j][ s[i] - 'a' ] == m);
        }
    }
    cout << dp[0][0] << '\n';
}
