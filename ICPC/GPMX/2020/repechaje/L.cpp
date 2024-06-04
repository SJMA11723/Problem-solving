#include<bits/stdc++.h>
#define MAXN 1e7+5
#define nMax 1e7+5
using namespace std;

/*vector<int> lp;

void cribaLineal(int n){
    if(n<2) return;
    lp.resize(n+1);
    lp.shrink_to_fit();

    for(int64_t i = 2; i * i <= n; i++){
        if(lp[i]) continue;
        lp[i] = i;
        for(int64_t j = i * i; j <= n; j += i) lp[j] = i;
    }

}*/


int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,A,B;
    cin >> n;

    //sacar la criba
    //cribaLineal( nMax);

    while( n-- ){
        cin >> A >> B;

        //marcar los divisores
        set<int> cnt;

        if(A % 2 == 0) cnt.insert(2);
        while(A % 2 == 0) A /= 2;

        for(int64_t i = 3; i * i <= A && A > 1; i += 2){
            if(A % i) continue;

            cnt.insert(i);
            while(A % i == 0) A /= i;
        }
        if(A > 1) cnt.insert(A);

        if(B % 2 == 0) cnt.insert(2);
        while(B % 2 == 0) B /= 2;

        for(int64_t i = 3; i * i <= B && B > 1; i += 2){
            if(B % i) continue;

            cnt.insert(i);
            while(B % i == 0) B /= i;
        }
        if(B > 1) cnt.insert(B);

        cout << cnt.size() << '\n';

    }


    return 0;
}
