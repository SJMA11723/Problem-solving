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
    set<int> mset;
    for(int i = 0 ; i < 4; ++i){
        int x; cin >> x;
        mset.insert(x);
    }
    cout << 4 - mset.size() << '\n';
}
