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
    int64_t arr[n], L[n], R[n];
    stack<int64_t> st;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        while(st.size() && arr[st.top()] > arr[i]){
            R[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while(st.size()){
        R[st.top()] = n;
        st.pop();
    }

    for(int i = n - 1; 0 <= i; --i){
        while(st.size() && arr[st.top()] > arr[i]){
            L[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while(st.size()){
        L[st.top()] = -1;
        st.pop();
    }

    int64_t ans = LLONG_MIN, l = INT_MAX, r = INT_MAX;
    for(int i = 0; i < n; ++i){
        if(ans < 1ll*arr[i] * (R[i] - L[i] - 1)){
            ans = 1ll*arr[i] * (R[i] - L[i] - 1);
            l = L[i] + 2;
            r = R[i];
        } else if(ans == 1ll*arr[i] * (R[i] - L[i] - 1) && L[i] + 2 < l){
            l = L[i] + 2;
            r = R[i];
        }
    }
    cout << l << ' ' << r << ' ' << ans << '\n';
}
