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
    while(t--){
        int n; cin >> n;
        int64_t k; cin >> k;
        string s; cin >> s;
        queue<int> q;
        for(int i = 0; i < n; ++i)
            if(s[i] == '0') q.push(i);

        string ans;
        int cur = 0;
        for(int i = 0; i < n; ++i){
            while(q.size() && q.front() < i) q.pop();
            while(cur < n && !s[cur]) cur++;

            if(q.size() && q.front() - i <= k){
                int idx = q.front();
                k -= idx - i;
                ans += '0';
                s[idx] = 0;
                q.pop();
            } else {
                ans += s[cur];
                s[cur] = 0;
            }
        }

        //cout << ans << '\n';

        while(cur < n){
            if(s[cur]) ans += s[cur];
            cur++;
        }

        //cout << k << '\n';

        cout << ans << '\n';
    }
}
