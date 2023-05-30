/**
* Author: Mathgic
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    map<string, int> cub;
    while(n--){
        int x; cin >> x;
        string name, str;
        while(x--){
            cin >> str;
            name += str[0];
        }
        cub[name]++;
    }

    int ans = 0;
    for(auto &it : cub) if(it.second == 1) ans++;
    cout << ans << '\n';
}
