/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int dfs(int nodo, int &ans, vector<int> grafo[], string &color){
    int con = 0;
    for(int &v : grafo[nodo]) con += dfs(v, ans, grafo, color);
    if(color[nodo - 1] == 'W') con++;
    else con--;
    if(con == 0) ans++;
    return con;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> grafo[n + 1];
        for(int i = 2; i <= n; ++i){
            int x; cin >> x;
            grafo[x].push_back(i);
        }
        string str; cin >> str;
        int ans = 0;
        dfs(1, ans, grafo, str);
        cout << ans << '\n';
    }
}
