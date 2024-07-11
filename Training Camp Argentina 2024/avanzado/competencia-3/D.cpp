/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1ll << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    if(n < k || k < __builtin_popcount(n)){
        cout << "NO\n";
        return 0;
    }

    priority_queue<int> pq;
    for(int i = 0; i <= 30; ++i)
        if(is_on(n, i)) pq.push(1 << i);

    while(pq.size() < k){
        int pot = pq.top();
        pq.pop();
        pq.push(pot / 2);
        pq.push(pot / 2);
    }

    cout << "YES\n";
    while(pq.size()){
        cout << pq.top() << " \n"[pq.size() == 1];
        pq.pop();
    }
}
