#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, c, k; cin >> r >> c >> k;
    int cnt[r + 1] = {};
    for(int i = 0; i < c; ++i){
        int h; cin >> h;
        cnt[h]++;
    }
    sort(cnt, cnt + r + 1, greater<int>());
    cout << accumulate(cnt, cnt + min(r, k), 0ll) << '\n';
}
