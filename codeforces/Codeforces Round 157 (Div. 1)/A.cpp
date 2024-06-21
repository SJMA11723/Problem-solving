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
    string n; cin >> n;
    for(int i = 0; i < n.size(); ++i){
        if(n[i] == '0'){
            n.erase(n.begin() + i);
            break;
        } else if(i + 1 == n.size()) n.pop_back();
    }
    cout << n << '\n';
}
