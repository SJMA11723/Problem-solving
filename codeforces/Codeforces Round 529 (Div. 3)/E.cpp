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
    char s[n + 1];
    s[0] = 0;
    int pref[n + 1]; pref[0] = 0;
    int mini_l[n + 1]; mini_l[0] = 1e9;
    for(int i = 1; i <= n; ++i){
        cin >> s[i];
        if(s[i] == '(') pref[i] = 1;
        else pref[i] = -1;
        pref[i] += pref[i - 1];
        mini_l[i] = min(mini_l[i - 1], pref[i]);
    }

    int mini_r[n + 2];
    mini_r[n + 1] = 1e9;
    for(int i = n; 1 <= i; --i) mini_r[i] = min(pref[i], mini_r[i + 1]);

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        if(s[i] == '('){
            if(mini_l[i - 1] >= 0 && pref[i - 1] > 0 && 0 <= mini_r[i + 1] - 2 && pref[n] - 2 == 0)
                ans++;
        } else {
            if(0 <= mini_l[i - 1] && 0 <= mini_r[i + 1] + 2 && pref[n] + 2 == 0)
                ans++;
        }
    }
    cout << ans << '\n';
}
