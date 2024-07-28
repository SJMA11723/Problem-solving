/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct max_stack{
    stack<pair<int64_t, int64_t>> st;

    max_stack(){st.push(make_pair(LLONG_MIN, LLONG_MIN));}

    void push(int64_t v){st.push(make_pair(v, max(v, st.top().second)));}

    int64_t top(){return st.top().first;}

    void pop(){if(st.size() > 1)st.pop();}

    int64_t maxV(){return st.top().second;}

    int size(){return st.size() -1;}

    bool empty(){return size() == 0;}
};

struct max_queue{
    void push(int64_t v){p_in.push(v);}

    int64_t front(){transfer(); return p_out.top();}

    void pop(){transfer(); p_out.pop();}

    int size(){return p_in.size() + p_out.size();}

    int64_t maxV() {return max(p_in.maxV(), p_out.maxV());}

    bool empty(){ return size() == 0;}
    void transfer(){
        if(p_out.size()) return;

        while(p_in.size()){
            p_out.push(p_in.top());
            p_in.pop();
        }
    }
    max_stack p_in;
    max_stack p_out;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, x; cin >> n >> k >> x;

    int arr[n];
    for(int &x : arr) cin >> x;

    max_queue q[x + 1];
    queue<int> indices[x + 1];
    for(int i = 0; i < x; ++i){
        q[i].push(LLONG_MIN);
        indices[i].push(0);
    }
    q[x].push(0);
    indices[x].push(0);

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < x; ++j){
            if(q[j + 1].maxV() == LLONG_MIN) continue;
            q[j].push(max(LLONG_MIN, q[j + 1].maxV() + arr[i - 1]));
            indices[j].push(i);
        }

        for(int j = 0; j <= x; ++j){
            while(indices[j].size() && indices[j].front() < i - k + 1){
                indices[j].pop();
                q[j].pop();
            }
        }
    }

    int64_t ans = LLONG_MIN;
    for(int i = 0; i < x; ++i) ans = max(ans, q[i].maxV());

    cout << (ans < 0 ? -1 : ans) << '\n';
}
