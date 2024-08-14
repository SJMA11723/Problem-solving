/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int dfs(int node, vector<int> tree[], int arr[], const int x, int &cnt, int p = -1){
    if(cnt == 2) return -1;

    int res = arr[node];
    for(int v : tree[node]){
        if(v == p || cnt == 2) continue;
        int tmp = dfs(v, tree, arr, x, cnt, node);

        if(tmp == x && cnt < 2) cnt++; //{cnt++; cout << "Found: " << v + 1 << '\n';}
        else res ^= tmp;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int arr[n], x = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            x ^= arr[i];
        }

        vector<int> tree[n];
        for(int i = 1; i < n; ++i){
            int a, b; cin >> a >> b;
            a--, b--;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        if(!x){
            cout << "YES\n";
            continue;
        }

        int cnt = 0;
        dfs(0, tree, arr, x, cnt);

        if(cnt == 2) cout << (k == 2 ? "NO\n" : "YES\n");
        else cout << "NO\n";
    }
}
