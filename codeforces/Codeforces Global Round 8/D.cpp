/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define is_on(S, i) ((S) & (1ll << (j)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int cub[20] = {};
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        for(int j = 0; j < 20; ++j)
            if(is_on(x, j)) cub[j]++;
    }

    int64_t ans = 0;
    int num;
    do{
        num = 0;
        for(int i = 0; i < 20; ++i){
            if(cub[i]){
                cub[i]--;
                num += 1 << i;
            }
        }
        ans += 1ll * num * num;
    }while(num);

    cout << ans << '\n';
}
