/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;

int n, d;
pair<int, int> pies[2][MAXN];
int ans[MAXN];

struct pos{
    bool elsie;
    int tastiness, id;
    int paso;
};

void bfs(){
    queue<pos> q;

    set<pair<pair<int, int>, int>> no_visitado[2];
    for(int i = 0; i < n; ++i){
        no_visitado[0].insert({{pies[0][i].first, pies[0][i].second}, i});
        no_visitado[1].insert({{pies[1][i].first, pies[1][i].second}, i});
    }


    for(int i = 0; i < n; ++i){
        if(pies[0][i].first == 0){
            q.push({0, pies[0][i].second, i, 1});
            no_visitado[0].erase({{pies[0][i].first, pies[0][i].second}, i});
        }
        if(pies[1][i].first == 0){
            q.push({1, pies[1][i].second, i, 1});
            no_visitado[1].erase({{pies[1][i].first, pies[1][i].second}, i});
        }
    }

    while(q.size()){
        pos act = q.front();
        q.pop();

        if(!act.elsie) ans[act.id] = act.paso;

        auto lwb = no_visitado[!act.elsie].lower_bound({{act.tastiness - d, -1}, -1});
        auto upb = no_visitado[!act.elsie].upper_bound({{act.tastiness, 2e9}, MAXN});

        for(auto it = lwb; it != upb; it = no_visitado[!act.elsie].erase(it))
            q.push({!act.elsie, it->first.second, it->second, act.paso + 1});
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("piepie.in");
    ofstream cout("piepie.out");
    cin >> n >> d;
    for(int i = 0; i < n; ++i)
        cin >> pies[0][i].second >> pies[0][i].first;
    for(int i = 0; i < n; ++i)
        cin >> pies[1][i].first >> pies[1][i].second;
    fill(ans, ans + n, -1);
    bfs();
    for(int i = 0; i < n; ++i){
        cout << ans[i] << '\n';
    }
}
