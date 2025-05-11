#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        string n; cin >> n;
        int N = n.size();

        bool add = true;
        int res = 0;
        for(int i = N - 1; 0 <= i; i -= 3){
            int num = n[i] - '0';
            if(0 <= i - 1) num += (n[i - 1] - '0') * 10;
            if(0 <= i - 2) num += (n[i - 2] - '0') * 100;
            if(add) res += num;
            else res -= num;
            add = !add;
        }
        cout << abs(res) << (res % 13 ? " NO\n" : " YES\n");
    }
}
