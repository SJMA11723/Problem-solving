/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, k;
bitset<1000001> ap;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    while(m--){
        int h; cin >> h;
        ap[h] = 1;
    }

    int pos = 1;
    if(ap[pos]){
        cout << pos << '\n';
        return 0;
    }

    while(k--){
        int a, b;
        cin >> a >> b;
        if(!ap[pos]){
            if(pos == a) pos = b;
            else if(pos == b) pos = a;
        }
    }

    cout << pos << '\n';
}
