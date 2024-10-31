#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        int ans = 0, cnt = 0;
        bool ok = false;
        for(int i = 0; i < n; ++i){
            if(s[i] == 'B'){
                if(cnt < 0){
                    ans = i;
                    cnt = 0;
                }
                cnt++;
            } else cnt--;
        }

        cnt = 0;
        ok = true;
        for(int i = ans; i < n; ++i){
            if(s[i] == 'B') cnt++;
            else cnt--;

            if(cnt < 0) ok = false;
        }

        for(int i = 0; i < ans; ++i){
            if(s[i] == 'B') cnt++;
            else cnt--;

            if(cnt < 0) ok = false;
        }

        if(!ok) ans = -1;

        cout << ans << '\n';
    }
}
