#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int ans = 0, n = s.size();
        for(int i = 0; i < n / 2; ++i){
            ans += abs(s[i] - s[n - 1 - i]);
        }
        cout << ans << '\n';
    }
}