/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int arr[18];

bool comp(pair<int, int> a, pair<int, int> b){
    int s1 = (a.second - a.first + 1);
    s1 *= s1;
    for(int i = a.first; i <= a.second; ++i) s1 -= arr[i];

    int s2 = (b.second - b.first + 1);
    s2 *= s2;
    for(int i = b.first; i <= b.second; ++i) s2 -= arr[i];

    return s1 < s2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<int, int>> op[19]; /// op[i]: operaciones para tener 0 1 ... (i - 1) dado que empezamos en 0 0 ... 0
    op[2] = {{1, 1}};

    for(int i = 3; i < 19; ++i){
        op[i] = op[i - 1]; /// 0 1 ... (i - 2) 0
        op[i].push_back({0, i - 1}); /// (i - 1) (i - 1) ... (i - 1)
        op[i].push_back({0, i - 2}); /// 0 0 0 ... 0 (i - 1)

        for(pair<int, int> o : op[i - 1]) op[i].push_back(o); /// 0 1 ... (i - 2) (i - 1)
    }

    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    vector<pair<int, int>> intervals;
    for(int i = 0; i < n; ++i){
        int sum = 0;
        for(int j = i; j < n; ++j){
            sum += arr[j];
            if(sum >= (j - i + 1) * (j - i + 1)) continue;

            intervals.push_back({i, j});
        }
    }

    sort(intervals.begin(), intervals.end(), comp);

    vector<pair<int, int>> ans_op;
    int ans_sum = 0;

    bool used[n] = {};
    while(intervals.size()){
        auto [l, r] = intervals.back();
        intervals.pop_back();

        bool ok = false;
        for(int i = l; i <= r; ++i) ok = ok || used[i];

        if(ok) continue;

        int sum = 0;
        bool positivo = true;
        for(int i = l; i <= r; ++i){
            used[i] = true;
            positivo = positivo && arr[i];
            sum += arr[i];
        }

        if(sum){
            ans_op.push_back({l + 1, r + 1});
            if(!positivo) ans_op.push_back({l + 1, r + 1});
        }

        ans_sum += (r - l + 1) * (r - l + 1);
        for(auto [i, j] : op[r - l + 1]) ans_op.push_back({i + l + 1, j + l + 1}); /// 0 1 2 ... (r - 1)
        ans_op.push_back({l + 1, r + 1}); /// r r ... r r
    }

    for(int i = 0; i < n; ++i) ans_sum += arr[i] * !used[i];

    cout << ans_sum << ' ' << ans_op.size() << '\n';

    for(auto [l, r] : ans_op) cout << l << ' ' << r << '\n';
}
