#include <bits/stdc++.h>

using namespace std;

bool vis[10][10];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool ans = true;
    int n; cin >> n;
    while(n--){
        int d, l, r, c;
        cin >> d >> l >> r >> c;
        r--, c--;
        if(d){ /// vertical
            for(int i = 0; i < l; ++i){
                if(vis[r + i][c]) ans = false;
                if(r + i >= 10){
                    ans = false;
                    break;
                }
                vis[r + i][c] = true;
            }
        } else {
            for(int i = 0; i < l; ++i){
                if(vis[r][c + i]) ans = false;
                if(c + i >= 10){
                    ans = false;
                    break;
                }
                vis[r][c + i] = true;
            }
        }
    }

    cout << (ans ? "Y\n" : "N\n");
}
