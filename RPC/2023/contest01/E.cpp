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
    long long n, ans = 0; cin >> n;
    stack<int> pila;
    long long pos[1000001] = {};
    for(long long i = 0; i < n; ++i){
        int x; cin >> x;
        while(pila.size() && pila.top() < x){
            pila.pop();
        }
        if(pila.size() && pila.top() == x && pos[x] + 1 != i){
            ans += i - 1 - pos[x];
        } else {
            pila.push(x);
        }
        pos[x] = i;
    }
    cout << ans << '\n';
}
