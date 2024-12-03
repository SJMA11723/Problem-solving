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
    int fact[11];
    fact[0] = 1;
    for(int i = 1; i <= 10; ++i) fact[i] = i * fact[i - 1];

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int64_t cnt[26] = {};
        for(char c : s) cnt[c - 'a']++;
        int64_t ans = LLONG_MAX;
        int a, b;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int64_t perm = fact[n];
                cnt[ s[i] - 'a' ]--;
                cnt[ s[j] - 'a' ]++;
                for(int k = 0; k < 26; ++k) perm /= fact[cnt[k]];
                if(perm <= ans){
                    a = i;
                    b = j;
                    ans = perm;
                }

                cnt[ s[i] - 'a' ]++;
                cnt[ s[j] - 'a' ]--;
            }
        }

        s[a] = s[b];
        cout << s << '\n';
    }
}
