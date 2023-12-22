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
        int arr[n];
        vector<int> ans;
        int idx = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            if(arr[i] > arr[idx]) idx = i;
        }

        ans.push_back(arr[idx]);
        arr[idx] = 0;
        int g = ans[0];

        while(ans.size() < n){
            int g2 = 0;
            for(int i = 0; i < n; ++i){
                if(!arr[i]) continue;
                if(g2 < gcd(arr[i], g)){
                    g2 = gcd(arr[i], g);
                    idx = i;
                }
            }
            ans.push_back(arr[idx]);
            g = g2;
            arr[idx] = 0;
        }
        for(int x : ans) cout << x << ' ';
        cout << '\n';
    }
}
