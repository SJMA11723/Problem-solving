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
        int a[n];
        set<float> areas;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            for(int j = 0; j < i; ++j) areas.insert((a[i] - a[j]) * 0.5);
        }
        cout << areas.size() << '\n';
    }
}
