#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
        }

        int num = 10 - n;
        cout << num * (num - 1) / 2 * 3 * 2 << '\n';
    }
}