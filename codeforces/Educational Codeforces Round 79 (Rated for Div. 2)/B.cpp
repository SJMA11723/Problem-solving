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
    int t;; cin >> t;
    while(t--){
        long long n, s; cin >> n >> s;
        long long suma = 0, posMaxi = 0;
        bool skip = false;
        priority_queue<pair<int, int>> heap;
        for(int i = 0; i < n; ++i){
            long long a; cin >> a;
            suma += a;
            if(!skip) heap.push({a, i + 1});
            if(suma > s) skip = true;
        }

        if(skip) cout << heap.top().second << '\n';
        else cout << "0\n";
    }
}
