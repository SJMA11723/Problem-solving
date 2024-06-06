/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> tree[n];
    for(int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int depth[n] = {};
    int prev[n];
    queue<int> q;
    q.push(0);
    depth[0] = 1;
    prev[0] = 0;

    while(q.size()){
        int u = q.front();
        q.pop();

        for(int v : tree[u]){
            if(depth[v]) continue;

            depth[v] = depth[u] + 1;
            prev[v] = u;
            q.push(v);
        }
    }

    int order[n] = {};
    pair<int, int> arr[n];
    int first;
    for(int i = 0; i < n; ++i){
        int x; cin >> x; x--;
        if(!i) first = x;
        order[x] = i;

        arr[i] = {depth[x], order[prev[x]]};
    }

    cout << ((!first && is_sorted(arr, arr + n)) ? "Yes\n" : "No\n");
}
