/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct level{
    int64_t dist;
    pair<int, int> begin, end;
};

bool comp(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    map<int, vector<pair<int, int>>> cub;
    for(int i = 0; i < n; ++i){
        int x, y; cin >> x >> y;
        cub[max(x, y)].push_back({x, y});
    }

    int n_levels = cub.size();
    vector<level> levels;
    for(auto &it : cub){
        sort(it.second.begin(), it.second.end(), comp);
        int64_t dist = 0;
        int x, y; tie(x, y) = it.second[0];
        for(auto [i, j] : it.second){
            dist += abs(x - i) + abs(y - j);
            x = i;
            y = j;
        }

        levels.push_back({dist, it.second[0], it.second.back()});
    }

    int64_t dp[2][2];
    dp[0][0] = levels[0].dist + levels[0].begin.first + levels[0].begin.second;
    dp[0][1] = levels[0].dist + levels[0].end.first + levels[0].end.second;

    for(int i = 1; i < n_levels; ++i){
        dp[i % 2][0] = levels[i].dist;
        dp[i % 2][0] += min(dp[(i - 1) % 2][0] + abs(levels[i].begin.first - levels[i - 1].end.first) + abs(levels[i].begin.second - levels[i - 1].end.second),
                            dp[(i - 1) % 2][1] + abs(levels[i].begin.first - levels[i - 1].begin.first) + abs(levels[i].begin.second - levels[i - 1].begin.second));

        dp[i % 2][1] = levels[i].dist;
        dp[i % 2][1] += min(dp[(i - 1) % 2][0] + abs(levels[i].end.first - levels[i - 1].end.first) + abs(levels[i].end.second - levels[i - 1].end.second),
                            dp[(i - 1) % 2][1] + abs(levels[i].end.first - levels[i - 1].begin.first) + abs(levels[i].end.second - levels[i - 1].begin.second));
    }

    cout << min(dp[(n_levels - 1) % 2][0], dp[(n_levels - 1) % 2][1]) << '\n';
}
