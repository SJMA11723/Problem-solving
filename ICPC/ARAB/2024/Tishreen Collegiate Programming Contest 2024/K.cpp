#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        string arr[n];
        for(string &s : arr) cin >> s;

        string st[m];
        for(string &s : st) cin >> s;

        int cntok = 0;
        for(int i = 0; i < k; ++i){
            string s; cin >> s;
            for(int j = 0; j < m; ++j){
                if(s == st[j]){
                    cntok++;
                    break;
                }
            }
        }

        cout << min({m - cntok + k - cntok, 1 + n - k, 1 + k}) << '\n';
    }
}