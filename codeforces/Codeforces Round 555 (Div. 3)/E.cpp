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
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    map<int, int> cub;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        cub[x]++;
    }

    for(int i = 0; i < n; ++i){
        int m = (n - a[i]) % n;
        auto it = cub.lower_bound(m);
        if(it == cub.end()){
            cout << (a[i] + cub.begin()->first) % n << " \n"[i + 1 == n];
            cub.begin()->second--;
            if(!cub.begin()->second) cub.erase(cub.begin());
            continue;
        }

        cout << (a[i] + it->first) % n << " \n"[i + 1 == n];
        it->second--;
        if(!it->second) cub.erase(it);
    }
}
