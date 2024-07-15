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

    vector<int> skill[m];
    for(int i = 0; i < n; ++i){
        int s, r; cin >> s >> r;
        s--;
        skill[s].push_back(r);
    }

    int ans = 0;
    int sum_acc[n] = {};
    for(vector<int> &v : skill){
        sort(v.begin(), v.end(), greater<int>());
        int sum = 0;
        for(int i = 0; i < v.size(); ++i){
            sum += v[i];
            if(sum < 0) break;
            sum_acc[i] += sum;
            ans = max(ans, sum_acc[i]);
        }
    }
    cout << ans << '\n';
}
