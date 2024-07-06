#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    while(t--){
        int n, w, h, pieces = 1;
        cin >> w >> h >> n;

        while(h % 2 == 0){
            pieces *= 2;
            h /= 2;
        }

        while(w % 2 == 0){
            pieces *= 2;
            w /= 2;
        }

        if(n <= pieces) cout << "YES\n";
        else cout << "NO\n";
    }

}