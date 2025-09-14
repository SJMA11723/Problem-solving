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
    string s; int d; cin >> s >> d;
    int n = s.size();

    vector<int> pi; pi.push_back(0);
    int ans = 1, prv = 0;
    for(int i = 1; i < n; ++i){
        int j = pi.back();
        while(j && s[i] != s[j + prv]) j = pi[prv + j - 1];
        pi.push_back(j + (s[i] == s[j + prv]));

        if(i + 1 - prv - pi.back() > d){
            ans++;
            pi.back() = 0;
            prv = i;
        }
    }
    cout << ans << '\n';
}
