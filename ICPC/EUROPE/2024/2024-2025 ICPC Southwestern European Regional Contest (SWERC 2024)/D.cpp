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
    int n; cin >> n;
    int64_t arr[n];
    int G[n] = {};
    stack<int> st;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];

        while(st.size() && arr[st.top()] < arr[i]){
            G[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }

    while(st.size()) st.pop();

    for(int i = n - 1; 0 <= i; --i){
        while(st.size() && arr[st.top()] < arr[i]){
            if(G[st.top()]) G[st.top()] = min(G[st.top()], st.top() - i);
            else G[st.top()] = st.top() - i;
            st.pop();
        }
        st.push(i);
    }
    while(st.size()) st.pop();

    int64_t ans = 0;
    cout << accumulate(G, G + n, 0ll) << '\n';
}
