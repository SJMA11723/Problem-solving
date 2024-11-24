#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b; cin >> a >> b;
    for(int x = -1e6; x <= b; ++x){
        int z = 3 * a - b - x;
        if(b <= z && abs(z) <= 1000000){
            cout << "3\n";
            cout << x << ' ' << b << ' ' << z << '\n';
            return 0;
        }
    }
}
