#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string t, p;
    cin >> t >> p;

    int n = t.size();
    int m = p.size();

    int ans = 0;
    for(int i = m - 1; i < n; ++i){
        bool ok = true;
        for(int j = 0; j < m; ++j){
            if(t[i - m + j + 1] == p[j]){
                ok = false;
                break;
            }
        }
        ans += ok;
    }
    cout << ans << '\n';
}