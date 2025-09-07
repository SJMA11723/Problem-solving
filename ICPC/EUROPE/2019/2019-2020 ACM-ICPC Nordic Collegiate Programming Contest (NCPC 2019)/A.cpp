#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    int n; cin >> n;
    string ans = "?";
    int cnt[27] = {};
    string arr[n];
    for(int i = 0; i < n; ++i){
        string t; cin >> t;
        if(t[0] == s.back() && ans == "?") ans = t;
        cnt[t[0] - 'a']++;
        arr[i] = t;
    }

    for(int i = 0; i < n; ++i){
        string &t = arr[i];
        if(t[0] == s.back() && cnt[t.back() - 'a'] - (t[0] == t.back()) == 0){
            cout << t << "!\n";
            return 0;
        }
    }

    cout << ans << '\n';
}