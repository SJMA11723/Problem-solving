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
    int cub[1001] = {};
    for(int i = 0; i < n * n; ++i){
        int x; cin >> x;
        cub[x]++;
    }

    int ans[n][n];
    memset(ans, 0, sizeof(ans));
    vector<pair<int, int>> groups[5];
    for(int i = 1; i <= 1000; ++i){
       if(cub[i] / 4) groups[4].push_back({i, cub[i] / 4});
       if(cub[i] % 4 / 2) groups[2].push_back({i, cub[i] % 4 / 2});
       if(cub[i] % 2) groups[1].push_back({i, 1});
    }

    bool ok = true;
    for(int i = 0; i < n / 2; ++i){
        for(int j = 0; j < n / 2; ++j){

            if(groups[4].empty()){
                ok = false;
                i = n;
                break;
            }

            ans[i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][j] = ans[n - 1 - i][n - 1 - j] = groups[4].back().first;

            groups[4].back().second--;
            if(!groups[4].back().second) groups[4].pop_back();
        }
    }

    if(n % 2){
        for(auto [x, cnt] : groups[4]) groups[2].push_back({x, 2 * cnt});

        for(int i = 0; i < n / 2; ++i){
            /// columna
            if(groups[2].empty()){
                ok = false;
                i = n;
                break;
            }

            ans[i][n / 2] = ans[n - 1 - i][n / 2] = groups[2].back().first;

            groups[2].back().second--;
            if(!groups[2].back().second) groups[2].pop_back();

            /// fila
            if(groups[2].empty()){
                ok = false;
                i = n;
                break;
            }

            ans[n / 2][i] = ans[n / 2][n - 1 - i] = groups[2].back().first;

            groups[2].back().second--;
            if(!groups[2].back().second) groups[2].pop_back();
        }

        for(auto [x, cnt] : groups[2]) groups[1].push_back({x, 2 * cnt});

        if(groups[1].empty()) ok = false;
        else ans[n / 2][n / 2] = groups[1].back().first;
    }

    if(ok){
        cout << "YES\n";
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) cout << ans[i][j] << " \n"[j + 1 == n];
    } else cout << "NO\n";
}
