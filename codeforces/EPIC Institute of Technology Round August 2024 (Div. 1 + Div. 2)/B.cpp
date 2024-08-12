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
        deque<int> a(n), b(n);
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;

        bool alice = true;
        for(int i = 1; i < n; ++i){
            if(a.front() != b.front() && a.front() != b.back()){
                break;
            } else if(a.back() != b.front() && a.back() != b.back()){
                break;
            } else if(a.front() == b.front()){
                a.pop_front();
                b.pop_front();
            } else {
                a.pop_front();
                b.pop_back();
            }
        }

        if(a.size() == 1 && a[0] == b[0]) alice = false;

        cout << (alice ? "Alice\n" : "Bob\n");
    }
}
