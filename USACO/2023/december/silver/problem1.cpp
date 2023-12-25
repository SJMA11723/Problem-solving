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
    int n, m, k;
    cin >> n >> m >> k;
    pair<int, long long> arr[n];
    for(int i = 0; i < n; ++i){
        int w, a;
        cin >> w >> a;
        arr[i] = {w, a};
    }
    sort(arr, arr + n);

    long long ans = 0;
    map<int, int> cub; cub[-k] = m;
    for(int i = 0; i < n; ++i){
        while(cub.begin()->first + k <= arr[i].first && arr[i].second){
            long long mini = min((int)arr[i].second, cub.begin()->second);
            arr[i].second -= mini;
            cub.begin()->second -= mini;
            cub[arr[i].first] += mini;
            ans += mini;
            if(cub.begin()->second == 0) cub.erase(cub.begin());
        }
    }
    cout << ans << '\n';
}
