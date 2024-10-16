#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x,y,z;
    int a,b,c;
    int r=0;
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    r+=(x<a?a-x:0);
    r+=(y<b?b-y:0);
    r+=(z<c?c-z:0);
    cout << r << endl;
}
