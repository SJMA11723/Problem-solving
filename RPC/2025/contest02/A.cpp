#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, r; cin >> n >> m >> r;
    string problems[n];
    int cnt_pending = 0;
    for(string &s : problems){
        cin >> s;
        for(char c : s) cnt_pending += c == 'P';
    }

    int rank[n];
    vector<int> teams;
    for(int i = 0; i < n; ++i){
        teams.push_back(i);
        rank[i] = i + 1;
    }

    int idx[n] = {};

    for(int i = 0; i < cnt_pending; ++i){
        int cur = teams.back();
        while(idx[cur] < m && problems[cur][idx[cur]] != 'P') idx[cur]++;
        if(idx[cur] == m){
            rank[cur] = teams.size();
            teams.pop_back();
            i--;
            continue;
        }

        string s; cin >> s >> s;

        for(int j = 0; j < 6; ++j) s.pop_back();

        int cnt_y = 0;
        while(s.back() == 'y'){
            cnt_y++;
            s.pop_back();
        }

        auto it = teams.end() - 1 - cnt_y;
        while(it != teams.end()){
            rank[*it] = it - teams.begin() + 2;
            it++;
        }
        rank[cur] = teams.size() - cnt_y;
        teams.insert(teams.end() - 1 - cnt_y, cur);
        teams.pop_back();

        problems[cur][idx[cur]] = '*';
    }

    cout << rank[r - 1] << '\n';
}
