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
    int H[n];
    int64_t sum[n];
    stack<int> st;
    for(int i = 1; i <= n; ++i){
        cin >> H[i];
        while(st.size() && H[st.top()] < H[i]) st.pop();
        if(st.empty()){
            sum[i] = 1ll*H[i] * i;
        } else {
            sum[i] = sum[st.top()] + 1ll*(i - st.top()) * H[i];
        }
        st.push(i);

        cout << sum[i] + 1 << " \n"[i == n];
    }
}
