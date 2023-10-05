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
    int n, q;
    cin >> n >> q;
    map<string, int> idx;
    for(int i = 0; i < n; ++i){
        string str; cin >> str;
        idx[str] = i;
    }

    while(q--){
        string l, r;
        cin >> l >> r;
        int idxI = idx[l], idxF = idx[r];
        if(idxF < idxI) swap(idxI, idxF);
        cout << idxF - idxI - 1 << '\n';
    }
}
