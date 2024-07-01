/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct elem{
    int64_t v, mini, maxi;
};

struct minmax_stack{
    stack<elem> st;

    minmax_stack(){st.push({LLONG_MAX, LLONG_MAX, LLONG_MIN});}

    void push(int64_t v){st.push({v, min(v, st.top().mini), max(v, st.top().maxi)});}

    int64_t top(){return st.top().v;}

    void pop(){if(st.size() > 1)st.pop();}

    int64_t minV(){return st.top().mini;}

    int64_t maxV(){return st.top().maxi;}

    int size(){return st.size() -1;}

    bool empty(){return size() == 0;}
};

struct minmax_queue{
    void push(int64_t v){p_in.push(v);}

    int64_t front(){transfer(); return p_out.top();}

    void pop(){transfer(); p_out.pop();}

    int size(){return p_in.size() + p_out.size();}

    int64_t minV() {return min(p_in.minV(), p_out.minV());}

    int64_t maxV() {return max(p_in.maxV(), p_out.maxV());}

    bool empty(){ return size() == 0;}
    void transfer(){
        if(p_out.size()) return;

        while(p_in.size()){
            p_out.push(p_in.top());
            p_in.pop();
        }
    }
    minmax_stack p_in;
    minmax_stack p_out;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; int64_t k;
    cin >> n >> k;
    int64_t arr[n];
    for(int64_t &x : arr) cin >> x;

    minmax_queue q;
    int64_t ans = 0;
    for(int i = 0; i < n; ++i){
        q.push(arr[i]);

        while(q.size() && q.maxV() - q.minV() > k) q.pop();

        ans += q.size();
    }
    cout << ans << '\n';
}
