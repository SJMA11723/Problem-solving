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
        int64_t n, k; cin >> n >> k;
        deque<int64_t> arr;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            arr.push_back(x);
        }

        while(arr.size() && k){
            int64_t mini = min(arr.front(), arr.back());
            if(arr.size() > 1){
                mini = min(mini, k / 2);
                if(!mini){
                    arr.front()--;
                    k--;
                } else {
                    arr.front() -= mini;
                    arr.back() -= mini;
                    k -= mini * 2;
                }
            } else {
                mini = min(mini, k);
                arr.front() -= mini;
                k -= mini;
            }

            //cout << arr.size() << ' ' << arr.front() << ' ' << arr.back() << ' ' << k << '\n';
            if(!arr.front()) arr.pop_front();
            if(arr.size() && !arr.back()) arr.pop_back();
        }

        cout << n - arr.size() << '\n';
    }
}
