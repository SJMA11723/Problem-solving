#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for(int i = 0; i < t; ++i){
        int n; cin >> n;
        int maxi = 0;
        while(n--){
            int x; cin >> x;
            maxi = max(maxi, x);
        }
        cout << "Case " << i + 1 << ": " << maxi << '\n';
    }
}
