/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1000001

using namespace std;

bool is_digit(char c){
    return c != '(' && c != ')';
}

vector<int> graph[MAXN + 1][2];
bool vis[MAXN + 1][2];

int dfs(int l, int r, string &str, int idx){
    if(l == r) return 0;

    int ini = l;

    while(ini < r && is_digit(str[ini])) ini++;

    int root = stoi(str.substr(l, ini - l));
    vis[root][idx] = true;

    int level = 0;
    for(int i = l; i < r; ++i){
        if(str[i] == '('){
            level++;
            if(level == 1) ini = i + 1;
        } else if(str[i] == ')'){
            if(level == 1){
                int hijo = dfs(ini, i, str, idx);
                graph[root][idx].push_back(hijo);
            }
            level--;
        }
    }

    return root;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string A, B, tmpA, tmpB;
    getline(cin, tmpA);
    getline(cin, tmpB);
    for(char c : tmpA)
        if(c != ' ') A += c;
    for(char c : tmpB)
        if(c != ' ') B += c;

    dfs(0, A.size(), A, 0);
    dfs(0, B.size(), B, 1);

    bool ok = true;
    for(int i = 1; i < MAXN; ++i)
        ok = ok && vis[i][0] == vis[i][1];

    for(int i = 1; i < MAXN; ++i){
        sort(graph[i][0].begin(), graph[i][0].end());
        sort(graph[i][1].begin(), graph[i][1].end());

        ok = ok && graph[i][0] == graph[i][1];
    }

    cout << (ok ? "Yes\n" : "No\n");
}
