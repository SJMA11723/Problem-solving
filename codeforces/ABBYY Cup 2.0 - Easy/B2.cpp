#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, res = 0;

    cin >> n;

    set<int> divisores;

    for(int i = 2, lim = sqrt(n); i <= lim; ++i){
        if(n % i == 0){
            divisores.insert(i);
            divisores.insert(n / i);
        }
    }

    if(!divisores.empty()){
        for(int it : divisores){
            while(n % it == 0){
                res += n;
                n /= it;
            }
        }

        res++;
    } else res = n + 1;

    cout << res;

}