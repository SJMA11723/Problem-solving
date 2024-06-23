/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXN 20001

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bitset<MAXN> sets[MAXN];
    int q; cin >> q;
    while(q--){
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(c == '+') sets[x].set(y);
        else if(c == '-') sets[x].reset(y);
        else if(c == 'v') cout << (sets[x] | sets[y]).count() << '\n';
        else if(c == '^') cout << (sets[x] & sets[y]).count() << '\n';
        else if(c == '!') cout << (sets[x] ^ sets[y]).count() << '\n';
        else cout << ((sets[x] | sets[y]) ^ sets[y]).count() << '\n';
    }
}
