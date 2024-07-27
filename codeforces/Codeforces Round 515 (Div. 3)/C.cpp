/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXID 200'000

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int pos[MAXID + 1] = {};

    int max_pos = 0, min_pos = 0;
    int q; cin >> q;

    char type; cin >> type;
    int id; cin >> id;
    q--;
    min_pos--;
    max_pos++;

    while(q--){
        cin >> type >> id;
        if(type == 'R') pos[id] = max_pos++;
        else if(type == 'L') pos[id] = min_pos--;
        else cout << min(pos[id] - min_pos - 1, max_pos - 1 - pos[id]) << '\n';
    }
}
