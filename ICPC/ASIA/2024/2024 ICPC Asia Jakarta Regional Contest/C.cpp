#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    int last[26];
    fill(last, last + 26, -1);
    for(int i = 0; i + 1 < t.size(); ++i) last[t[i] - 'a'] = i;

    int ans = INT_MAX, pref = 0, suff = 0;
    for(int i = 0; i + 1 < s.size(); ++i){
        char c = s[i + 1] - 'a';
        if(last[c] == -1) continue;

        int len = i + 1 + (int)t.size() - last[c];
        if(len < ans && last[c] + 1 < t.size()){
            ans = len;
            pref = i + 1;
            suff = last[c];
        }
    }

    if(ans == INT_MAX) cout << "-1\n";
    else cout << s.substr(0, pref) + t.substr(suff) << '\n';
}
