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
        int n, m, v; cin >> n >> m >> v;
        int64_t arr[n];
        int cnt = 0, L[n], R[n];
        int64_t sum = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            sum += arr[i];
            if(sum >= v){
                cnt++;
                sum = 0;
            }
            L[i] = cnt;
        }

        if(L[n - 1] < m){
            cout << "-1\n";
            continue;
        }

        sum = 0, cnt = 0;
        for(int i = n - 1; 0 <= i; --i){
            sum += arr[i];
            if(sum >= v){
                cnt++;
                sum = 0;
            }
            R[i] = cnt;
        }

        //for(int x : L) cout << x << ' '; cout << '\n';
        //for(int x : R) cout << x << ' '; cout << '\n';

        int64_t ans = 0;

        for(int i = 1; i < n; ++i) arr[i] += arr[i - 1];

        for(int i = 0; i < n; ++i){
            int l;
            if(i) l = L[i - 1];
            else l = 0;
            l = min(l, m);
            int r = m - l;

            int lo = i, hi = n;
            while(lo < hi){
                int mid = lo + (hi - lo) / 2;
                if(R[mid] >= r) lo = mid + 1;
                else hi = mid;
            }
            if(r) lo -= 2;
            else lo--;
            if(lo < i) continue;

            if(i) ans = max(ans, arr[lo] - arr[i - 1]);
            else ans = max(ans, arr[lo]);

            //cout << i << ' ' << ans << ' ' << l << ' ' << r << ' ' << lo << '\n';
        }

        cout << ans << '\n';
    }
}
