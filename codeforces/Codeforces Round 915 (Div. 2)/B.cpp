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
        int grade[n + 1] = {};
        for(int i = 1; i < n; ++i){
            int a, b; cin >> a >> b;
            grade[a]++;
            grade[b]++;
        }
        int leaf = 0;
        for(int i = 1; i <= n; ++i) leaf += grade[i] == 1;
        cout << (leaf + 1) / 2 << '\n';
    }
}
