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
        int n, x; cin >> n >> x;
        map<int, int> cnt;
        int arr[n];
        for(int &v : arr) cin >> v;
        sort(arr, arr + n);
        int mex = 0;
        priority_queue<int, vector<int>, greater<int>> pending;
        for(int &v : arr){
            //cout << v << ' ' << mex << '\n';
            if(v == mex) mex++;
            else if(v < mex) cnt[v % x]++;
            else {
                while(cnt[mex % x] && v > mex){
                    cnt[mex % x]--;
                    mex++;
                    while(pending.size() && pending.top() <= mex){
                        cnt[pending.top() % x]++;
                        pending.pop();
                    }
                }

                if(v == mex) mex++;
                else pending.push(v);
            }
            while(pending.size() && pending.top() <= mex){
                cnt[pending.top() % x]++;
                pending.pop();
            }
            //cout << mex << '\n';
        }
        while(cnt[mex % x]){
            cnt[mex % x]--;
            mex++;
        }

        cout << mex << '\n';
    }
}
