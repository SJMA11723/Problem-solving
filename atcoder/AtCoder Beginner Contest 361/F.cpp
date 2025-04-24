/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int64_t n; cin >> n;

    /**
       Consideremos x = a^b, para algun 2 <= b <= 64 y la factorizacion en primos de
       x = p1^{q1}p2^{q2}p3^{q3}...pn^{qn}. Entonces b >= 2 es un divisor de g = gcd(q1, ..., qn)
       con a = p1^{q1 / b}p2^{q2 / b}p3^{q3 / b}...pn^{qn / b}. No importa cual b elijamos para
       x, solo debemos contar x una vez. Podemos simplificar b a que todos sus exponentes en su
       factorizacion prima sean 1, pues si b = P1^Q1P2^Q2 es divisor de g, entonces b' = PQ también
       es divisor de g. Ahora usando inclusion-exlusion sumamos todos los x cuando b = p, restamos
       cuando b = pq, sumamos cuando b = pqr, etc.
    */

    int64_t ans = 1; /// cuento x = 1 a parte
    for(int b = 2; b < 60; ++b){
        /// cuento cuantas a existen tales que a^b <= n
        /// equivalentemente cuantos x = a^b para algun a.
        int l = 1, r = 1e9 + 1;
        while(l < r){
            int mid = l + (r - l) / 2;

            __int128_t powmid = 1;
            int cnt_exp = 0;
            while(cnt_exp < b && powmid <= n) powmid *= mid, cnt_exp++;

            if(powmid > n) r = mid;
            else l = mid + 1;
        }
        r--;

        int tmpb = b;
        bool ok_exp = true, par_primes = 0;
        for(int i = 2; i * i <= tmpb && ok_exp; ++i){
            if(tmpb % i) continue;

            tmpb /= i;
            if(tmpb % i == 0){ /// no todos sus exponentes son 1
                ok_exp = false;
            }

            par_primes ^= 1;
        }
        if(tmpb > 1) par_primes ^= 1;

        if(!ok_exp) continue;

        /// sumamos r - 1 para no contar a = 1
        ans += (r - 1) * (par_primes ? 1 : -1);
    }
    cout << ans << '\n';
}
