/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 1001

using namespace std;

struct edge{
    int to;
    int c;
    const bool operator<(const edge &b)const{
        return c > b.c;
    }
};

vector<edge> grafo[MAXN];
int eCost[MAXN];
bool visitado[MAXN];

int prim(){
    memset(visitado, 0, sizeof(visitado));
    fill(eCost, eCost + MAXN, INT_MAX);

    long long ans = 0;
    priority_queue<edge> q;
    q.push(edge{1, 0});
    while(q.size()){
        int node = q.top().to;
        long long c = q.top().c;
        q.pop();

        if(visitado[node]) continue;
        visitado[node] = true;

        ans = max(ans, c);

        for(edge it : grafo[node]){
            if(visitado[it.to] || eCost[it.to] <= it.c) continue;
            eCost[it.to] = it.c;
            q.push(it);
        }
    }

    return ans;
}

int cost(const string &a, const string &b, int n){
    int ret = 0;
    for(int i = 0; i < n; ++i){
        ret += abs(a[i] - b[i]);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    string words[n];
    for(int i = 0; i < n; ++i) cin >> words[i];

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int c = cost(words[i], words[j], k);
            grafo[i].push_back(edge{j, c});
            grafo[j].push_back(edge{i, c});
        }
    }

    cout << prim() << '\n';
}
