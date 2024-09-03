#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t fibo[45];

    fibo[0]=1;
    fibo[1]=1;

    for( int i=2; i<=41; i++ ) fibo[i] = fibo[i-1] + fibo[i-2];
//    for( int i=2; i<=44; i++ ) cout << i << ' ' << fibo[i] << '\n';


    int n; cin >> n;

    cout << fibo[n] <<'\n';



}
