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
    string s; cin >> s;
    bool ans[n], ok = true;
    for(int i = 0; i < n; ++i){
        bool allm = true, one = false, zero = false;
        char max_c = 0; bool ans_max;
        for(int j = 0; j < i; ++j){
            if(s[j] <= s[i]){
                if(s[j] >= max_c){
                    max_c = s[j];
                    ans_max = ans[j];
                }
                continue;
            }
            if(ans[j]) one = true;
            else zero = true;
            ans[i] = !ans[j];
            allm = false;
        }

        if(allm) ans[i] = i ? ans_max : 0;

        if(one && zero){
            ok = false;
            break;
        }
    }

    if(ok){
        cout << "YES\n";
        for(int i = 0; i < n; ++i) cout << ans[i];
        cout << '\n';
    } else cout << "NO\n";
}
