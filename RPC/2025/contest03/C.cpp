#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b; cin >> a >> b;
    int ans = 0;
    for(int y = 1; y * y <= b; ++y){
        int yy = y * y;
        if(yy < a) continue;
        ans += 15;
    }
    cout << ans << '\n';
}
