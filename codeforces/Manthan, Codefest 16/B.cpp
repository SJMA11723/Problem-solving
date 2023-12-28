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
    int m; cin >> m;
    int ceros = 0, cnt = 0;
    vector<int> ans;
    int n = 1;
    while(ceros <= m){
        int tmp = n;
        while(tmp % 2 == 0){
            if(cnt < 0) ceros++;
            cnt++;
            tmp /= 2;
        }

        while(tmp % 5 == 0){
            if(cnt > 0) ceros++;
            cnt--;
            tmp /= 5;
        }

        if(ceros == m) ans.push_back(n);
        n++;
    }

    cout << ans.size() << '\n';
    for(int x : ans) cout << x << ' ';
    cout << '\n';
}
