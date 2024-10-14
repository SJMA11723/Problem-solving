#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    int m; cin >> m;
    int ans = 0;
    for(char c = 'a'; c <= 'z'; ++c){
        int l = 0;
        int cnt_m = 0, cnt = 0;
        for(int r = 0; r < n; ++r){
            if(s[r] == c) cnt++;
            else cnt_m++;

            while(cnt_m > m){
                if(s[l] == c) cnt--;
                else cnt_m--;
                l++;
            }

            ans = max(ans, cnt);
        }
    }
    cout << ans << '\n';
}
