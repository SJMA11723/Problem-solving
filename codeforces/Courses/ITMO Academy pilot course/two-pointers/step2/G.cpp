/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct gcd_stack{
    stack<pair<int64_t, int64_t>> st;

    gcd_stack(){st.push(make_pair(0, 0));}

    void push(int64_t v){st.push(make_pair(v, __gcd(v, st.top().second)));}

    int64_t top(){return st.top().first;}

    void pop(){if(st.size() > 1)st.pop();}

    int64_t gcd(){return st.top().second;}

    int size(){return st.size() -1;}

    bool empty(){return size() == 0;}
};

struct gcd_queue{
    void push(int64_t v){p_in.push(v);}

    int64_t front(){transfer(); return p_out.top();}

    void pop(){transfer(); p_out.pop();}

    int size(){return p_in.size() + p_out.size();}

    int64_t gcd() {return __gcd(p_in.gcd(), p_out.gcd());}

    bool empty(){ return size() == 0;}
    void transfer(){
        if(p_out.size()) return;

        while(p_in.size()){
            p_out.push(p_in.top());
            p_in.pop();
        }
    }
    gcd_stack p_in;
    gcd_stack p_out;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int64_t arr[n];
    for(int64_t &x : arr) cin >> x;

    int ans = INT_MAX, r = 0;
    gcd_queue q;
    for(int i = 0; i < n; ++i){
        q.pop();

        while(r < n && q.gcd() != 1) q.push(arr[r++]);

        if(q.gcd() == 1) ans = min(ans, q.size());
    }
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}
