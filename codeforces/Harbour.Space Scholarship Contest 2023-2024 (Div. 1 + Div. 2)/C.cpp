/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_power_of_two(S) (!((S) & ((S) - 1)))
#define lsb(S) ((S) & (-S))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        vector<int> ans;
        while(!is_power_of_two(x)){
            ans.push_back(x);
            x -= lsb(x);
        }

        while(x > 1){
            ans.push_back(x);
            x /= 2;
        }
        cout << ans.size() + 1 << '\n';
        for(int d : ans) cout << d << ' ';
        cout << "1\n";
    }
}
