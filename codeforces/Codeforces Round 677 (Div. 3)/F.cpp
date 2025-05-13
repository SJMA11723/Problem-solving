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
    int n, m, k; cin >> n >> m >> k;
    int N = n * m;
    pair<int, int> arr[N];
    map<int, vector<int>> cub;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int x; cin >> x;
            arr[i * m + j] = {x, j};
        }
    }

    int cnt[m] = {};
    for(int i = 0; i < N; ++i){
        int x, j;
        tie(x, j) = arr[i];
    }

}
