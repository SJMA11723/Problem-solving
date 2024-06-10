#include<bits/stdc++.h>
using namespace std;

int p(int n){
    return (n>=500)? n-100: n;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c;
    cin >> a >> b >>c;

    //caso 1;
    int mini = p(a) + p(b) + p(c);
    mini = min( mini, p(a+b+c)   );
    mini = min( mini, p(a+b) + p(c)   );
    mini = min( mini, p(c+b) + p(a)   );
    mini = min( mini, p(a+c) + p(b)   );


    cout << mini << '\n';

    return 0;
}
