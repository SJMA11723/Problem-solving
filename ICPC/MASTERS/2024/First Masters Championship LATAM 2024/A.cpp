#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int A, B, C; cin >> A >> B >> C;
    int cnt = 1, money = 0, ans = 0;
    cnt += money / A;
    money %= A;
    money += cnt * B;
    while(cnt < C){
        cnt += money / A;
        money %= A;
        money += cnt * B;
        ans++;
    }
    cout << ans << '\n';
}
