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
    set< vector< pair<int, int> > > mset;
    int n; cin >> n;
    while(n--){
        int m; cin >> m;
        vector< pair<int, int> > puntos;
        puntos.reserve(1000);
        while(m--){
            int x, y;
            cin >> x >> y;
            puntos.push_back({x, y});
        }
        sort(puntos.begin(), puntos.end());

        for(int i = 1; i < puntos.size(); ++i){
            puntos[i].first -= puntos[0].first;
            puntos[i].second -= puntos[0].second;
        }
        puntos[0] = {0, 0};

        mset.insert(puntos);
    }

    /*for(auto &it : mset){
        for(auto &p : it){
            cout << p.first << ' ' << p.second << '\n';
        }
        cout << '\n';
    }*/

    cout << mset.size() << '\n';
}
