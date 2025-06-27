/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

long long dp[100001][2];
map<int, pair<long long, long long>> mapa;

struct pos{
    long long x, min_y, max_y;
    pos(long long a, long long b, long long c): x(a), min_y(b), max_y(c){}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        long long x, y;
        cin >> x >> y;
        if(mapa.find(x) == mapa.end()) mapa[x] = {LLONG_MAX, LLONG_MIN};
        mapa[x].first = min( mapa[x].first, y );
        mapa[x].second = max( mapa[x].second, y );
    }

    vector<pos> columnas;
    for(auto it : mapa){
        pair<long long, long long> p = it.second;
        if(p != make_pair(LLONG_MAX, LLONG_MIN)){
            columnas.push_back(pos(it.first, p.first, p.second));
        }
    }

    n = columnas.size();
    dp[n - 1][0] = dp[n - 1][1] = 0;
    for(int i = n - 2; 0 <= i; --i){
        long long y_mn, y_mx, yy_mn, yy_mx;
        y_mn = columnas[i].min_y;
        y_mx = columnas[i].max_y;
        yy_mn = columnas[i + 1].min_y;
        yy_mx = columnas[i + 1].max_y;


        long long dist_x = columnas[i + 1].x - columnas[i].x;
        /// Arriba a arriba - quedo abajo en la siguiente
        long long dist_y = abs(y_mx - yy_mx) + yy_mx - yy_mn;
        dp[i][0] = dist_x + dist_y + dp[i + 1][1];

        /// Arriba a abajo - quedo arriba en el siguiente
        dist_y = abs(y_mx - yy_mn) + yy_mx - yy_mn;
        dp[i][0] = min(dp[i][0], dist_x + dist_y + dp[i + 1][0]);

        /// Abajo a abajo - quedo arriba en el siguiente
        dist_y = abs(y_mn - yy_mn) + yy_mx - yy_mn;
        dp[i][1] = dist_x + dist_y + dp[i + 1][0];

        /// Abajo a arriba - quedo abajo en el siguiente
        dist_y = abs(y_mn - yy_mx) + yy_mx - yy_mn;
        dp[i][1] = min(dp[i][1], dist_x + dist_y + dp[i + 1][1]);
    }

    cout << columnas[0].max_y - columnas[0].min_y + min(dp[0][0], dp[0][1]) << '\n';
}
