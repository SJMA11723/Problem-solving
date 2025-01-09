#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;
        int c = 1;
        for(int i = 0; i < n; ++i){
            switch(c){
                case 1:
                    cout << 'a';
                    c++;
                    break;
                case 2:
                    cout << 'b';
                    c++;
                    break;
                default:
                    cout << 'c';
                    c = 1;
                    break;
            }
        }
        cout << '\n';
    }
}