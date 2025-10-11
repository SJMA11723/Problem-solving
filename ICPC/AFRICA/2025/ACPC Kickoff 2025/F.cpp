/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

#define MAXVAL 10000000

using namespace std;

void dfs(int u, vector<int> graph[], char ans[], bool &ok){
    for(int v : graph[u]){
        if(ans[v]){
            if(ans[v] == ans[u]) ok = false;
            continue;
        }
        ans[v] = ans[u] == '1' ? '2' : '1';
        dfs(v, graph, ans, ok);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    unordered_map<int, vector<int>> ap, cub;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        ap[x].pb(i);
        if(!(x & 1)) cub[2].pb(i);
    }

    bitset<MAXVAL + 1> no_prime;
    no_prime[0] = no_prime[1] = 1;
    for(int64_t i = 3; i <= MAXVAL; i += 2){
        if(no_prime[i]) continue;
        for(int64_t j = i; j <= MAXVAL; j += i){
            no_prime[j] = 1;
            if(ap.count(j)) for(int x : ap[j]) cub[i].pb(x);
        }
    }

    vector<int> graph[n];
    for(auto &it : cub){
        if(it.se.size() > 2){
            cout << "-1\n";
            return 0;
        } else if(it.se.size() == 2){
            int a = it.se[0], b = it.se[1];
            graph[a].pb(b);
            graph[b].pb(a);
        }
    }

    char ans[n] = {};
    bool ok = true;
    for(int i = 0; i < n && ok; ++i){
        if(ans[i]) continue;
        ans[i] = '1';
        dfs(i, graph, ans, ok);
    }

    if(ok) for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    else cout << "-1\n";
}
