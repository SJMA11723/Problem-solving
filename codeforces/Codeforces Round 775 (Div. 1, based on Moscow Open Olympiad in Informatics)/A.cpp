/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

#define MAXC 100000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> cubi[MAXC + 1], cubj[MAXC + 1];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int x; cin >> x;
            cubi[x].push_back(i);
            cubj[x].push_back(j);
        }
    }

    int64_t ans = 0;
    for(int i = 1; i <= MAXC; ++i){
        if(cubi[i].empty()) continue;
        sort(all(cubi[i]));
        sort(all(cubj[i]));

        int64_t sum = 0, sum2 = 0;
        for(int j = 0; j < cubi[i].size(); ++j){
            ans += 1ll * cubi[i][j] * j - sum;
            ans += 1ll * cubj[i][j] * j - sum2;

            sum += cubi[i][j];
            sum2 += cubj[i][j];
        }
    }
    cout << ans << '\n';
}
