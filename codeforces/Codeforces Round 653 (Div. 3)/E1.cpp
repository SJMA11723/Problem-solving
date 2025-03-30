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
    int n, k; cin >> n >> k;
    vector<int> A, B, both;
    for(int i = 0; i < n; ++i){
        int time, a, b;
        cin >> time >> a >> b;
        if(a && b) both.push_back(time);
        else if(a) A.push_back(time);
        else if(b) B.push_back(time);
    }

    if(min(A.size(), B.size()) + both.size() < k){
        cout << "-1\n";
        return 0;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(both.begin(), both.end());

    for(int i = 1; i < A.size(); ++i) A[i] += A[i - 1];
    for(int i = 1; i < B.size(); ++i) B[i] += B[i - 1];
    for(int i = 1; i < both.size(); ++i) both[i] += both[i - 1];

    int ans = INT_MAX;
    for(int i = 0; i <= both.size(); ++i){
        if(i < k){
            if(k - 1 - i < min(A.size(), B.size())) ans = min(ans, A[k - 1 - i] + B[k - 1 - i] + (i ? both[i - 1] : 0));
        } else ans = min(ans, both[i - 1]);
    }
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}
