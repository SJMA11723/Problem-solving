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
    string s; cin >> s;
    int color[26] = {};
    int ans[n];
    for(int i = 0; i < n; ++i){
        vector<int> colors;
        for(int j = s[i] - 'a' + 1; j < 26; ++j) colors.push_back(color[j]);
        sort(colors.begin(), colors.end());
        int mex = 1;
        for(int c : colors){
            if(mex == c) mex++;
        }

        ans[i] = mex;
        color[ s[i] - 'a' ] = max(color[ s[i] - 'a' ], mex);
    }

    cout << *max_element(ans, ans + n) << '\n';
    for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
