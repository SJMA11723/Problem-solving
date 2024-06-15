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

    map<string, string> lista;

    map<string, int> cnt;

    for(int i = 1; i < n; ++i){
        string a, b; cin >> a >> b;
        lista[b] = a;
        cnt[a]++;
        cnt[b]++;
    }

    string act;
    for(auto &it : cnt){
        if(it.second == 1 && lista[it.first].size()){
            act = it.first;
            break;
        }
    }

    while(act.size()){
        cout << act << '\n';
        act = lista[act];
    }
}
