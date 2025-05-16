/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int64_t pos; cin >> pos;
        int n = s.size();
        int64_t max_pos = n, prv = 0;
        s += '\0';

        if(pos <= n){
            cout << s[pos - 1];
            continue;
        }

        vector<char> st;
        for(int i = 0; i < s.size(); ++i){
            while(st.size() && st.back() > s[i]){
                prv = max_pos;
                max_pos += --n;
                st.pop_back();
                if(pos <= max_pos){
                    pos -= prv; pos--;
                    if(pos < st.size()) cout << st[pos];
                    else cout << s[i + pos - (int)st.size()];
                    i = s.size();
                    break;
                }
            }

            st.push_back(s[i]);
        }
    }
    cout << '\n';
}
