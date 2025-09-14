#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n; cin >> n;
    set<int64_t> ans;
    for(int64_t i = 1; i * i <= n; ++i){
        vector<int64_t> coef;
        int64_t tmp = n;
        while(tmp && i > 1){
            coef.push_back(tmp % i);
            tmp /= i;
        }
        if(i > 1){
            bool ok = true;
            for(int j = 0; j < coef.size() / 2; ++j)
                ok = ok && coef[j] == coef[(int)coef.size() - 1 - j];
            if(ok) ans.insert(i);
        }

        if(n % i == 0){
            int64_t x = n / i - 1;
            if(1 < x && i < x) ans.insert(x);
            x = i - 1;
            if(1 < x && n / i < x) ans.insert(x);
        }
    }

    if(ans.size()) for(int64_t x : ans) cout << x << " \n"[x == *ans.rbegin()];
    else cout << "*\n";
}
