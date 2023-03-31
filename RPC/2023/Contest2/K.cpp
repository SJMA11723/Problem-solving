/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct pos{
    long long any = 0,
              left = 0,
              right = 0;
};

map<string, pos> mapa;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    bool impossible = true;
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        string tipo, dir;
        int a;
        cin >> tipo >> dir >> a;
        if(dir == "any") mapa[tipo].any += a;
        else if(dir == "left") mapa[tipo].left += a;
        else mapa[tipo].right += a;
    }

    for(auto &p : mapa){
        pos it = p.second;
        if(it.any > 1 || it.left * (it.right + it.any) != 0 || it.right * (it.left + it.any) != 0)
            impossible = false;

        if(it.left + it.right == 0) ans++;
        else ans += max(it.right, it.left);
    }
    ans++;

    if(impossible) cout << "impossible\n";
    else cout << ans << '\n';
}
