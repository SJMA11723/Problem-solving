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
    int n, x, y; cin >> n >> x >> y;
    int cnt_lesseq = 0;
    for(int i = 0; i < n; ++i){
        int v; cin >> v;
        cnt_lesseq += v <= x;
    }
    cout << (x > y ? n : (cnt_lesseq + 1) / 2) << '\n';
}
