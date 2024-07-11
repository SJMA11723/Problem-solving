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
    int n, m; cin >> n >> m;

    vector<pair<int, int>> events[n];
    int prepare[m], day[m];
    for(int i = 0; i < m; ++i){
        int s, d, c; cin >> s >> d >> c;
        s--; d--;
        events[s].push_back({0, i});
        events[d].push_back({1, i});
        prepare[i] = c;
        day[i] = d;
    }

    priority_queue<pair<int, int>> pending_prepare;
    int ans[n], passed_exams = 0;
    for(int i = 0; i < n; ++i){
        while(pending_prepare.size() && -pending_prepare.top().first < i) pending_prepare.pop();

        bool activity = false;
        for(auto [t, e] : events[i]){
            if(t){
                if(!prepare[e]){
                    passed_exams++;
                    activity = true;
                    ans[i] = m + 1;
                }
            } else {
                pending_prepare.push({-day[e], e});
            }
        }

        if(!activity){
            ans[i] = 0;
            if(pending_prepare.size()){
                int e = pending_prepare.top().second;

                prepare[e]--;
                ans[i] = e + 1;

                if(!prepare[e]) pending_prepare.pop();
            }
        }
    }

    if(passed_exams != m) cout << "-1\n";
    else for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
