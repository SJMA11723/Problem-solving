#include <bits/stdc++.h>

using namespace std;

int strHash(string str){
    if(str == "Tetrahedron")
        return 4;
    if(str == "Cube")
        return 6;
    if(str == "Octahedron")
        return 8;
    if(str == "Dodecahedron")
        return 12;
    return 20;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        ans += strHash(s);
    }
    cout << ans;
}