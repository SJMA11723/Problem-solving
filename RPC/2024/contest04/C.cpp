#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int ant = 0, ans = 1, cnt = 0;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(ant < x){
            cnt++;
        } else cnt = 1;
        ans = max(ans, cnt);
        ant = x;
    }
    cout << ans << '\n';
}
