#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,x,y;
    cin >> a >> x >> b >> y;

    if( x+y == a+b ) cout << "D" << "\n";
    if( x+y > a+b ) cout << "P" << "\n";
    if( x+y < a+b ) cout << "A" << "\n";

    return 0;
}
