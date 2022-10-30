#include <bits/stdc++.h>

using namespace std;

int act[60001], maxi = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;

    while(n--){
        int a, b;
        cin >> a >> b;
        act[a]++;
        act[b]--;
    }

    for(int i = 1; i < 60001; ++i){
        act[i] += act[i - 1];
        maxi = max(maxi, act[i]);
    }

    bool enMax = false;

    cout << maxi << '\n';

    for(int i = 1; i < 60001; ++i){
        if(act[i] == maxi){
            if(!enMax) cout << i << ' ';
            enMax = true;
        } else {
            if(enMax) cout << i << '\n';
            enMax = false;
        }
    }
}