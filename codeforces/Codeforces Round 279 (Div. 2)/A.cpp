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
    vector<int> cub[4];
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        cub[x].push_back(i);
    }
    cout << min({cub[1].size(), cub[2].size(), cub[3].size()}) << '\n';
    while(cub[1].size() && cub[2].size() && cub[3].size()){
        cout << cub[1].back() << ' ' << cub[2].back() << ' ' << cub[3].back() << '\n';
        cub[1].pop_back();
        cub[2].pop_back();
        cub[3].pop_back();
    }
}
