/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, char> a, pair<int, char> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        string s, c; cin >> s;
        int idx[m];
        for(int i = 0; i < m; ++i){
            cin >> idx[i];
            idx[i]--;
        }
        cin >> c;

        sort(idx, idx + m);
        sort(c.begin(), c.end());

        int l = 0, r = m - 1;
        for(int i = 0; i < m; ++i){
            if(i + 1 < m && idx[i] == idx[i + 1]) s[ idx[i] ] = c[r--];
            else s[ idx[i] ] = c[l++];
        }
        cout << s << '\n';
    }
}
