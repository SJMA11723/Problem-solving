#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    int ans = 0;
    for(int i = 0; i <= k; ++i){
        if(i * n + n - 1 <= k) ans = i;
    }
    cout << ans << '\n';
}
