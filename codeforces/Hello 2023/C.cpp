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
        int n, m; cin >> n >> m;
        int arr[n];
        for(int &x : arr) cin >> x;

        int64_t target = 0;
        for(int i = 0; i < m; ++i) target += arr[i];

        int ans = 0;
        int64_t sum = target;
        priority_queue<int> pq;
        for(int i = m - 1; 0 <= i; --i){
            while(sum < target){
                target -= 2 * pq.top();
                pq.pop();
                ans++;
            }

            sum -= arr[i];
            pq.push(arr[i]);
        }

        while(pq.size()) pq.pop();

        sum = target;
        for(int i = m; i < n; ++i){
            sum += arr[i];
            pq.push(-arr[i]);

            while(sum < target){
                sum += 2 * pq.top();
                pq.pop();
                ans++;
            }
        }

        cout << ans << '\n';
    }
}
