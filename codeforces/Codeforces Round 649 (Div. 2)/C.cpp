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

    if(n == 1){
        cout << !a[0] << '\n';
        return 0;
    }

    set<int> pending;
    for(int i = 0; i <= n; ++i) pending.insert(i);
    pending.erase(a[n - 1]);

    bool ok = true;
    int ans[n];
    for(int i = 1; i < n; ++i){
        if(a[i] != a[i - 1]){
            ans[i] = a[i - 1];
            if(!pending.count(ans[i])){
                ok = false;
                break;
            }
            pending.erase(ans[i]);
        }
    }

    if(a[0] == 1){
        ans[0] = 0;
        if(!pending.count(0)) ok = false;
        pending.erase(0);
    } else {
        ans[0] = *pending.begin();
        pending.erase(pending.begin());
    }

    for(int i = 1; i < n; ++i){
        if(a[i] != a[i - 1]) continue;

        auto it = pending.begin();
        if(*it == a[i - 1]){
            it++;
            if(it == pending.end()){
                ok = false;
                break;
            }
        }

        ans[i] = *it;
        pending.erase(it);
    }

    pending.clear();
    for(int i = 0; i <= n; ++i) pending.insert(i);
    for(int i = 0; i < n; ++i){
        pending.erase(ans[i]);
        if(a[i] != *pending.begin()){
            ok = false;
            break;
        }
    }

    if(!ok){
        cout << "-1\n";
        return 0;
    }

    for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
