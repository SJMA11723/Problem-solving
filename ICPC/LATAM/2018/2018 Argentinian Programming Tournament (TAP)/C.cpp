#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y, z, w;
    cin >> x >> y >> z >> w;
    x--, y--, z--, w--;

    char first[3] = {'4', '6', '2'};
    char period[8] = {'4', '8', '3', '2', '6', '1', '2', '2'};
    if(x < 3) cout << first[x];
    else cout << period[(x - 3) % 8];

    if(y < 3) cout << first[y];
    else cout << period[(y - 3) % 8];

    if(z < 3) cout << first[z];
    else cout << period[(z - 3) % 8];

    if(w < 3) cout << first[w];
    else cout << period[(w - 3) % 8];
    cout << '\n';
}
