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
    int n; cin >> n;
    bool ap[n] = {};
    int arr[n];
    for(int &x : arr){
        cin >> x;
        x--;
        if(x >= 0) ap[x] = true;
    }

    bool vis[n] = {};
    vector<pair<int, int>> even, odd;
    for(int i = 0; i < n; ++i){
        if(ap[i]) continue;

        int u = i, cnt = 1;
        while(!vis[u]){
            cnt++;
            vis[u] = true;
            if(arr[u] == -1){
                cnt--;
                break;
            }
            u = arr[u];
        }

        if(cnt % 2) odd.push_back({i, u});
        else even.push_back({i, u});
    }

    int u_e = -1, v_e = -1;
    if(even.size()){
        u_e = even[0].first;
        v_e = even.back().second;
        for(int i = 1; i < even.size(); ++i)
            arr[even[i - 1].second] = even[i].first;
        arr[v_e] = u_e;
    }

    if(odd.size()){
        for(int i = 1; i < odd.size(); i += 2){
            arr[odd[i - 1].second] = odd[i].first;
            arr[odd[i].second] = odd[i - 1].first;
        }

        if(odd.size() % 2){
            if(even.empty()){
                tie(u_e, v_e) = odd.back();
                odd.pop_back();
                int m = odd.size();

                arr[v_e] = odd[m - 2].first;
                arr[odd.back().second] = u_e;
            } else {
                arr[v_e] = odd.back().first;
                arr[odd.back().second] = u_e;
            }

        }
    }

    for(int i = 0; i < n; ++i) cout << arr[i] + 1 << " \n"[i + 1 == n];
}
