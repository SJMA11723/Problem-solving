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
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        int64_t n; cin >> n;
        vector<int64_t> ans;
        ans.push_back(1);
        for(int64_t i = 2; i * i <= n; ++i){
            if(n % i) continue;
            int last = (int)ans.size() - 1;
            int64_t powp = 1;
            bool ltr = true;
            while(n % i == 0){
                powp *= i;
                n /= i;
                ltr = !ltr;
                if(ltr) for(int j = 0; j <= last; ++j) ans.push_back(ans[j] * powp);
                else for(int j = last; 0 <= j; --j) ans.push_back(ans[j] * powp);
            }
        }
        if(n > 1){
            int last = (int)ans.size() - 1;
            for(int j = last; 0 <= j; --j) ans.push_back(ans[j] * n);
        }

        cout << "Case " << tt << ":\n";
        for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}
