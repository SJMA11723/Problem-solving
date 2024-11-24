#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int ans = 0;
        if(b < a) swap(a, b);
        while(ans + 1 <= a) a -= ++ans;
        if(a){
            ans++;
            b -= ans - a;
            a = 0;
        }
        while(ans + 1 <= b) b -= ++ans;

        cout << ans << '\n';
    }
}
