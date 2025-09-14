#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        char c;
        int cnt = 0;
        for(int j = 0; j < n; ++j){
            cin >> c;
            if(c == 'B'){
                ans += cnt / 2;
                cnt = 0;
            } else cnt++;
        }
        ans += cnt / 2;
    }

    cout << ans << '\n';

    return 0;
}
