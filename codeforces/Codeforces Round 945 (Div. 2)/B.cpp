/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

template<typename T> struct or_stack{
    stack<pair<T, T>> st;
    or_stack(){}
    or_stack(const T &e){init(e);}
    void init(const T &e){st.push(make_pair(e, e));}
    void push(const T &v){st.push(make_pair(v, st.top().second | v));}
    T top(){return st.top().first;}
    void pop(){if(st.size() > 1) st.pop();}
    T OR(){return st.top().second;}
    int size(){return st.size() - 1;}
    bool empty(){return size() == 0;}
};

template<typename T> struct or_queue{
    or_queue(const T e){p_in.init(e); p_out.init(e);}
    void push(const T &v){p_in.push(v);}
    T front(){transfer(); return p_out.top();}
    void pop(){transfer(); p_out.pop();}
    int size(){return p_in.size() + p_out.size();}
    T OR(){return p_in.OR() | p_out.OR();}
    bool empty(){return size() == 0;}
    void transfer(){
        if(p_out.size()) return;
        while(p_in.size()){
            p_out.push(p_in.top());
            p_in.pop();
        }
    }
    or_stack<T> p_in, p_out;
};

bool check(int n, int arr[], int k){
    or_queue<int> q(0);
    for(int i = 0; i < k; ++i) q.push(arr[i]);
    set<int> vals;
    vals.insert(q.OR());
    for(int i = k; i < n; ++i){
        q.pop();
        q.push(arr[i]);
        vals.insert(q.OR());
    }
    return vals.size() == 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int &x : arr) cin >> x;

        int l = 1, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(check(n, arr, mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
}
