/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void generateStr(int n, string s, vector<string> &str){
    if(n == 0){
        str.push_back(s);
        return;
    }

    for(char c = 'a'; c <= 'f'; ++c) generateStr(n - 1, s + c, str);
}

bool dfs(int pos, char cpos, string &s, vector<pair<string, char>> &op){
    if(pos + 1 == s.size()){
        if(cpos == 'a') return true;
        return false;
    }

    for(int i = 0; i < op.size(); ++i){
        if(cpos + s.substr(pos + 1, 1) == op[i].first){
            if(dfs(pos + 1, op[i].second, s, op)) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<string> str;
    generateStr(n, "", str);
    vector<pair<string, char>> op;
    while(q--){
        string s;
        char c;
        cin >> s >> c;
        op.push_back({s, c});
    }

    int ans = 0;
    for(string &it : str){
        if(dfs(0, it[0], it, op)) ans++;
    }
    cout << ans;
}
