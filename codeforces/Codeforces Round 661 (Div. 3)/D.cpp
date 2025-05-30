/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define ff first
#define ss second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> seq0, seq1;
        int ans[n] = {};
        for(int i = 0; i < n; ++i){
            if(s[i] == '0'){
                if(seq1.size()){
                    ans[i] = seq1.back();
                    seq1.pop_back();
                } else ans[i] = seq1.size() + seq0.size() + 1;
                seq0.push_back(ans[i]);
            } else {
                if(seq0.size()){
                    ans[i] = seq0.back();
                    seq0.pop_back();
                } else ans[i] = seq1.size() + seq0.size() + 1;
                seq1.push_back(ans[i]);
            }
        }
        cout << seq0.size() + seq1.size() << '\n';
        for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
    }
}
