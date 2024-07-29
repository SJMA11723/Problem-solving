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
    int cub[101] = {};
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        cub[x]++;
    }

    int ans = 0;
    bool rem = false;
    for(int i = 1; i <= 100; ++i){
        ans += rem;
        if(cub[i] % 2 == 0) continue;
        rem = !rem;
    }
    cout << ans << '\n';
}
