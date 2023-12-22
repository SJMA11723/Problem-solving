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
    int n; cin >> n;
    unordered_set<int> mset;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        while(x % 2 == 0) x /= 2;
        while(x % 3 == 0) x /= 3;
        mset.insert(x);
    }
    cout << (mset.size() == 1 ? "YES\n" : "NO\n");
}
