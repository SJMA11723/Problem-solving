/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 1000000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cnt[MAXVAL + 1] = {};
    int ans = 1;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        cnt[x]++;
        if(cnt[x] > 1) ans = max(ans, x);
    }

    for(int i = 1; i <= MAXVAL; ++i){
        bool first = false;
        for(int j = i; j <= MAXVAL; j += i)
        if(cnt[j]){
            if(first){
                ans = max(ans, i);
                break;
            }
            first = true;
        }
    }
    cout << ans << '\n';
}
