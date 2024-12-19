/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 5000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        cout << "1 " << n << ' ';
        bitset<MAXN> a(s), res("1");
        int l = 1, r = 1;
        for(int i = 0; i < n; ++i)
        if(s[i] == '0'){
            l = r = i + 1;
            res.reset();
            break;
        }
        res ^= a;

        for(int i = 0; i < n; ++i){
            if(s[i] == '0') continue;
            int last = -1;
            for(int j = 0; i + j < n; ++j){
                if(s[n - 1 - j] == '0') last = j;
            }
            if(last == -1) continue;

            bitset<MAXN> b(s.substr(i, last + 1));
            b ^= a;

            for(int j = MAXN - 1; 0 <= j; --j){
                if(res[j] == b[j]) continue;
                if(b[j]){
                    res = b;
                    l = i + 1;
                    r = i + 1 + last;
                }
                break;
            }
        }

        cout << l << ' ' << r << '\n';
    }
}
