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
    int n, m; cin >> n >> m;
    vector<int> arr;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        arr.push_back(x);
    }
    arr.push_back(m);

    int sum_off = 0;
    for(int i = 1; i < arr.size(); i += 2) sum_off += arr[i] - arr[i - 1];

    int ans = m - sum_off, sum_on = 0;
    for(int i = 0; i < arr.size(); ++i){
        if(i % 2){ /// lights on
            sum_off -= arr[i] - arr[i - 1];

            if(arr[i - 1] < arr[i] - 1){
                ans = max(ans, sum_on + sum_off + 1);
                //cout << i << ' ' << sum_on << ' ' << sum_off << '\n';
            }
        } else { /// lights off
            if(i) sum_on += arr[i] - arr[i - 1];
            else sum_on += arr[i];

            if(i + 1 < arr.size() && arr[i] + 1 < arr[i + 1]){
                ans = max(ans, sum_on + sum_off - 1);
                //cout << i << ' ' << sum_on << ' ' << sum_off << '\n';
            }
        }
    }
    cout << ans << '\n';
}
