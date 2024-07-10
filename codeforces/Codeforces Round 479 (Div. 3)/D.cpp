/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    pair<int, int64_t> a[n];
    for(auto &p : a){
        cin >> p.second;
        int64_t tmp = p.second;
        int cnt = 0;
        while(tmp % 3 == 0){
            tmp /= 3;
            cnt++;
        }
        p.first = -cnt;
    }
    sort(a, a + n);
    for(int i = 0; i < n; ++i) cout << a[i].second << " \0"[i + 1 == n];
}
