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
        string a, b; cin >> a >> b;
        vector<int> ans;
        int l = 0, r = n - 1;
        bool flip = false;
        for(int i = n - 1; 0 < i; --i){
            if(flip && a[l] != b[i]){
                l++;
                continue;
            } else if(!flip && a[r] == b[i]){
                r--;
                continue;
            }

            int d = (flip ? a[r] : a[l]) - '0';
            if((d ^ flip) == b[i] - '0') ans.push_back(1);
            ans.push_back(i + 1);
            if(flip) r--;
            else l++;

            flip ^= 1;
        }

        if(((a[l] - '0') ^ flip) != b[0] - '0') ans.push_back(1);


        cout << ans.size() << " \n"[ans.empty()];
        for(int i = 0; i < ans.size(); ++i) cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}
