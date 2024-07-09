/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <stdio.h>
#include <stack>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    long long arr[n];

    long long ans = 0;
    stack<long long> st;
    for(int i = 0; i < n; ++i){
        scanf("%lld", &arr[i]);
        while(st.size() && st.top() <= arr[i]){
            ans = max(ans, st.top() ^ arr[i]);
            st.pop();
        }
        st.push(arr[i]);
    }

    long long nxt = st.size() ? st.top() : 0;
    while(st.size()){
        ans = max(ans, st.top() ^ nxt);
        nxt = st.top();
        st.pop();
    }

    for(int i = n - 1; 0 <= i; --i){
        while(st.size() && st.top() <= arr[i]){
            ans = max(ans, st.top() ^ arr[i]);
            st.pop();
        }
        st.push(arr[i]);
    }

    nxt = st.size() ? st.top() : 0;
    while(st.size()){
        ans = max(ans, st.top() ^ nxt);
        nxt = st.top();
        st.pop();
    }

    printf("%lld\n", ans);
}
