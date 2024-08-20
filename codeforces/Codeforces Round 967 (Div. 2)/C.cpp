/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        bool vis[n + 1] = {};
        set<int> pending;
        for(int i = 2; i <= n; ++i) pending.insert(i);
        vector<pair<int, int>> ans;

        vis[1] = true;
        while(pending.size()){
            int l = 1, r = *pending.begin();

            int mid = 0;
            while(true){
                cout << "? " << l << ' ' << r << endl;
                cin >> mid;
                if(!vis[mid]) r = mid;
                else if(l == mid) break;
                else l = mid;
            }

            ans.push_back({l, r});
            vis[r] = true;
            pending.erase(r);
        }

        cout << "! ";
        for(int i = 0; i < ans.size(); ++i){
            int u, v;
            tie(u, v) = ans[i];
            cout << u << ' ' << v;
            if(i + 1 < ans.size()) cout << ' ';
        }
        cout << endl;
    }
}
