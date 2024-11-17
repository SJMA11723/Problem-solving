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
        int b, n; cin >> b >> n;
        int arr[n];
        for(int &x : arr) cin >> x;

        int ans = -1, ans_danger = INT_MAX, ans_cost = INT_MAX;
        for(int h = 0; h <= 100; ++h){
            int danger = 0;
            int cost = 0;
            for(int i = 0; i < n; ++i){
                if(arr[i] < h) danger += h - arr[i];
                else cost += arr[i] - h;
            }

            if(cost <= b){
                if(danger < ans_danger){
                    ans_danger = danger;
                    ans_cost = cost;
                    ans = h;
                } else if(danger == ans_danger && cost < ans_cost){
                    ans_cost = cost;
                    ans = h;
                }
            }
        }

        cout << ans << '\n';
    }
}
