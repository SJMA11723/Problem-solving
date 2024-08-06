#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cub[101] = {};
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            cub[x]++;
        }

        bool ok = false;
        while(!ok){
            ok = true;
            for(int i = 0 ; i < 101; ++i){
                if(cub[i]){
                    ok = false;
                    cout << i << ' ';
                    cub[i]--;
                }
            }
        }
        cout << '\n';
    }
}