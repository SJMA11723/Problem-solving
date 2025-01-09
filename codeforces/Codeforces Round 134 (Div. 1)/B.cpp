/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

void compute(int a, int b, const int n, string &s){
    if(s.size() > n){
        s = "";
        return;
    }

    if(a > b){
        s += "T";
        compute(a - b, b, n, s);
    } else if(a < b){
        s += "B";
        compute(a, b - a, n, s);
    } else if(a == 1) s += "T";
    else s = "";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, r; cin >> n >> r;

    int ans = INT_MAX;
    string s_ans;
    for(int i = 1; i <= r; ++i){
        string s;
        compute(r, i, n, s);
        if(s.size() == n){
            int cnt = 0;
            for(int j = 1; j < n; ++j) cnt += s[j] == s[j - 1];
            if(cnt < ans){
                ans = cnt;
                s_ans = s;
            }
        }

        s = "";
        compute(i, r, n, s);
        if(s.size() == n){
            int cnt = 0;
            for(int j = 1; j < n; ++j) cnt += s[j] == s[j - 1];
            if(cnt < ans){
                ans = cnt;
                s_ans = s;
            }
        }
    }

    if(ans == INT_MAX) cout << "IMPOSSIBLE\n";
    else {
        reverse(s_ans.begin(), s_ans.end());
        cout << ans << '\n' << s_ans << '\n';
    }
}
