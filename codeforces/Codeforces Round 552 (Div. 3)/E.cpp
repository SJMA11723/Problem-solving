/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct fenwick_tree{
    int n;
    vector<int> BIT;

    fenwick_tree(int _n){
        BIT.resize(n + 1);
        n = _n;
    }

    void add(int x, int pos){
        while(pos <= n){
            BIT[pos] += x;
            pos += pos & -pos;
        }
    }

    int sum(int pos){
        int res = 0;
        while(pos){
            res += BIT[pos];
            pos -= pos & -pos;
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int arr[n + 1];
    bool ans[n + 1];
    priority_queue<pair<int, int>> pq;
    set<int> pending;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        pq.push({arr[i], i});
        pending.insert(i);
    }

    bool second = false;
    while(pq.size()){
        int cur, pos;
        tie(cur, pos) = pq.top();
        pq.pop();

        if(!pending.count(pos)) continue;

        auto it = pending.find(pos);
        it++;
        for(int i = 0; i < k && it != pending.end(); ++i){
            ans[*it] = second;
            it = pending.erase(it);
        }

        it = pending.find(pos);
        vector<set<int>::iterator> erased;
        for(int i = 0; i <= k; ++i){
            ans[*it] = second;
            erased.push_back(it);
            if(it == pending.begin()) break;
            it--;
        }

        while(erased.size()){
            pending.erase(erased.back());
            erased.pop_back();
        }

        second = !second;
    }

    for(int i = 1; i <= n; ++i) cout << ans[i] + 1;
    cout << '\n';
}
