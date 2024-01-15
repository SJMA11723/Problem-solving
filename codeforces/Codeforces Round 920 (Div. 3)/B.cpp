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
        string A, B;
        cin >> A >> B;
        int cnt_0 = 0, cnt_1 = 0;
        for(int i = 0; i < n; ++i){
            if(A[i] == B[i]) continue;
            if(A[i] == '1') cnt_1++;
            else cnt_0++;
        }
        cout << max(cnt_0, cnt_1) << '\n';
    }
}
