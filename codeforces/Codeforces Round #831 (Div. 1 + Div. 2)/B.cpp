#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long long perimeter = 0, maxi = 0;
        while(n--){
            long long a, b;
            cin >> a >> b;
            perimeter += min(a, b);
            maxi = max(maxi, max(a, b));
        }
        perimeter = perimeter * 2 + maxi * 2;
        cout << perimeter << '\n';
    }
}
