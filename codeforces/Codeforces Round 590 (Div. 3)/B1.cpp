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
    int n, k; cin >> n >> k;
    set<int> ap;
    queue<int> q;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(ap.count(x)) continue;
        if(q.size() < k){
            q.push(x);
            ap.insert(x);
            continue;
        }
        ap.erase(q.front());
        q.pop();
        q.push(x);
        ap.insert(x);
    }

    vector<int> ans;
    while(q.size()){
        ans.push_back(q.front());
        q.pop();
    }

    cout << ans.size() << '\n';
    for(int i = (int)ans.size() - 1; 0 <= i; --i) cout << ans[i] << " \n"[!i];
}
