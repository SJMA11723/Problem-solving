/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

using namespace std;

int pairs(int n){
    return n * (n - 1) / 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cnt[26] = {};
    while(n--){
        string s; cin >> s;
        cnt[s[0] - 'a']++;
    }

    int ans = 0;
    for(int i = 0; i < 26; ++i) ans += pairs(cnt[i] / 2) + pairs(cnt[i] - cnt[i] / 2);
    cout << ans << '\n';
}
