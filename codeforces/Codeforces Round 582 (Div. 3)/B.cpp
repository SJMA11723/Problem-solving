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
        stack<int> st;
        int ans = 0;
        while(n--){
            int x; cin >> x;
            while(st.size() && st.top() > x){
                st.pop();
                ans++;
            }
            st.push(x);
        }
        cout << ans << '\n';
    }
}
