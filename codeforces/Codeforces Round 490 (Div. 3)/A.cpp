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
    int n, k; cin >> n >> k;
    deque<int> a;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        a.push_back(x);
    }

    while(a.size() && (a.front() <= k || a.back() <= k)){
        if(a.front() <= k){
            a.pop_front();
            continue;
        }

        if(a.back() <= k){
            a.pop_back();
            continue;
        }
    }
    cout << n - a.size() << '\n';
}
