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
    int cub[m] = {};
    int arr[n];
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        arr[i] = x;
        cub[x % m]++;
    }

    int target = n / m;
    set<int> available;
    for(int i = 0; i < m; ++i){
        if(cub[i] <= target) continue;
        available.insert(i);
    }

    vector<int> pass[m];
    int64_t ans = 0;
    for(int i = 0; i < m; ++i){
        if(cub[i] >= target) continue;

        while(cub[i] < target){

            auto l = available.upper_bound(i);
            if(l == available.begin()) l = available.end();
            l--;

            int mini = min(target - cub[i], cub[*l] - target);
            ans += 1ll*mini * abs((i - *l + m) % m);
            cub[i] += mini;
            cub[*l] -= mini;

            while(mini--) pass[*l].push_back((i - *l + m) % m);
            if(cub[*l] == target) available.erase(l);
        }
    }

    cout << ans << '\n';
    for(int i = 0; i < n; ++i){
        if(pass[ arr[i] % m ].size()){
            int d = pass[ arr[i] % m ].back();
            pass[ arr[i] % m ].pop_back();
            arr[i] += d;
        }
        cout << arr[i] << " \n"[i + 1 == n];
    }
}
