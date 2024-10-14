#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, r; cin >> n >> r;
    int l = r - 1;
    r = (1 << n) - l;
    for(int i = 0; i < n; ++i){
        if(l % 2){
            r--;
            l = l / 2 + 1;

            r /= 2;
        } else {
            r /= 2;
            l /= 2;
        }

        if(r < 1){
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << n << '\n';
}
