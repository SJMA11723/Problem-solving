#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> graph[n];
    int indeg[n] = {};
    for(int i = 0; i < m; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        indeg[b]++;
    }

    bool pending[n] = {};
    int registered = 0;
    for(int i = 0; i < n; ++i){
        int x; cin >> x; x--;

        pending[x] = true;
        if(!indeg[x]){
            queue<int> q;
            q.push(x);
            while(q.size()){
                int cur = q.front();
                q.pop();

                registered++;

                for(int v : graph[cur]){
                    indeg[v]--;
                    if(pending[v] && !indeg[v]) q.push(v);
                }
            }
        }

        cout << registered << '\n';
    }
}
