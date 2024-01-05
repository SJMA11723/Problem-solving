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
        string str; cin >> str;
        int64_t ans = 0;
        priority_queue<int64_t> add;
        for(int i = 0; i < n; ++i){
            if(str[i] == 'L'){
                ans += i;
                if(i < n / 2) add.push(n - i - 1 - i);
            } else {
                ans += n - i - 1;
                if(i >= n / 2) add.push(i - (n - i - 1));
            }
        }
        for(int i = 0; i < n; ++i){
            if(add.size()){
                ans += add.top();
                add.pop();
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
}
