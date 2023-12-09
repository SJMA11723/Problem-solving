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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pair<long long, int> ord[n];
        long long acc[n]; acc[0] = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            ord[i] = {x, i};
        }
        sort(ord, ord + n);

        acc[0] = ord[0].first;
        for(int i = 1; i < n; ++i) acc[i] = ord[i].first + acc[i - 1];
        int ans[n];

        for(int i = 0; i < n; ++i){
            const int idx = ord[i].second;
            long long score = acc[i];
            ans[idx] = i;
            while(true){
                int next = upper_bound(ord, ord + n, make_pair(score, n + 1)) - ord;
                next--;
                if(score >= acc[next]) break;
                score = acc[next];
                ans[idx] = next;
            }
        }

        for(int i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';
    }
}
