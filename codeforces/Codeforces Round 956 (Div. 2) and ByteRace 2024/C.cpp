/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, int64_t k, vector<vector<int>> &arr, const vector<int> &P){
    vector<int> res(6);
    int init = 0;
    for(int l = 0; l < 3; ++l){
        int j = P[l];
        int64_t sum = 0;
        for(int i = init; i < n; ++i){
            sum += arr[j][i];
            if(sum >= k){
                res[j * 2] = init + 1;
                res[j * 2 + 1] = i + 1;
                init = i + 1;
                break;
            }
        }
        if(sum < k) return {-1};
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n), b(n), c(n);
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        for(int &x : c) cin >> x;

        int64_t k = 0;
        for(int64_t x : c) k += x;
        k = (k + 2) / 3;

        vector<vector<int>> all = {a, b, c};
        vector<int> ans, P = {0, 1, 2};
        do{
            ans = solve(n, k, all, P);
            if(ans[0] != -1) break;
        }while(next_permutation(P.begin(), P.end()));

        for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}
