#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cnt = 0;
    while(n--){
        char c;
        int x;
        cin >> c >> x;
        if(c == 'P') cnt += x;
        else {
            if(cnt + 1 <= x) cout << "YES\n";
            else cout << "NO\n";
            cnt = max(0, cnt - x);
        }
    }
}
