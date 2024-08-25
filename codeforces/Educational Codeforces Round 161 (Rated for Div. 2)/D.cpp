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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        set<int> pending;
        int attack[n], defense[n];
        for(int &x : attack) cin >> x;

        for(int i = 0; i < n; ++i){
            cin >> defense[i];
            pending.insert(i);
        }

        for(int i = 0; i < n; ++i){
            if(i) defense[i - 1] -= attack[i];
            if(i + 1 < n) defense[i + 1] -= attack[i];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; ++i) pq.push({defense[i], i});

        bool died[n] = {};
        for(int i = 0; i < n; ++i){
            int ans = 0;
            set<int> changes;
            while(pq.size() && (pq.top().first < 0 || died[pq.top().second])){
                if(died[pq.top().second]){
                    pq.pop();
                    continue;
                }

                ans++;
                auto it = pending.find(pq.top().second);
                auto l = it, r = it;

                bool la = 0, ra = 0;

                if(*r != *pending.rbegin()){
                    r++;
                    ra = true;
                }

                if(l != pending.begin()){
                    l--;
                    la = true;
                }

                if(la){
                    defense[*l] += attack[*it];
                    if(ra) defense[*l] -= attack[*r];
                    changes.insert(*l);
                }

                if(ra){
                    defense[*r] += attack[*it];
                    if(la) defense[*r] -= attack[*l];
                    changes.insert(*r);
                }

                pq.pop();
                changes.erase(*it);
                died[*it] = true;
                pending.erase(it);
            }

            for(int idx : changes) pq.push({defense[idx], idx});

            cout << ans << " \n"[i + 1 == n];
        }
    }
}
