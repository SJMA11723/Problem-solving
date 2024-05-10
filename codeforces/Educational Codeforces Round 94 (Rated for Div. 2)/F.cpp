/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int K = 10;

struct Vertex {
    int next[K];
    bool output = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - '0';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].output = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - '0';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

int x;

bool check(string str){
    for(int i = 0; i < str.size(); ++i){
        int sum = 0;
        for(int j = i; j < str.size(); ++j){
            sum += str[j] - '0';
            if(sum != x && x % sum == 0) return false;
        }
    }
    return true;
}

void generate_xprime(string str, int sum, vector<string> &words){
    if(sum > x) return;
    if(sum == x){
        if(check(str)) words.push_back(str);
        return;
    }

    for(int i = 1; i < 10; ++i){
        generate_xprime(str + char(i + '0'), sum + i, words);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    s = "." + s;
    cin >> x;
    vector<string> xprimes;
    generate_xprime("", 0, xprimes);

    for(string &p : xprimes) add_string(p);

    int dp[t.size()][n + 1];
    for(int i = 0; i < t.size(); ++i)
        for(int j = 0; j <= n; ++j) dp[i][j] = INT_MAX;
    dp[0][0] = 0;

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < t.size(); ++j){
            if(dp[j][i - 1] == INT_MAX) continue;
            dp[j][i] = min(dp[j][i], dp[j][i - 1] + 1);

            int transition = go(j, s[i]);
            if(t[transition].output) continue;
            dp[transition][i] = min(dp[transition][i], dp[j][i - 1]);
        }
    }

    int ans = INT_MAX;
    for(int i = 0; i < t.size(); ++i) ans = min(ans, dp[i][n]);
    cout << ans << '\n';
}
