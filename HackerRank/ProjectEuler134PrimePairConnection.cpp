/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef __int128_t ull;

ull LLLabs(ull n){return n < 0 ? -n : n;}

ostream & operator<<(ostream &os, const ull &n){
    string num;
    bool negative = n < 0;
    ull tmp = LLLabs(n);
    while(tmp){
        num += tmp % 10 + '0';
        tmp /= 10;
    }
    if(negative) num += '-';
    reverse(num.begin(), num.end());

    if(num.empty()) num = "0";

    os << num;
    return os;
}

ull binExp(ull a, ull b, ull MOD){
    ull ans = 1;
    a %= MOD;
    while(b){
        if(b % 2) ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

void criba(int n, vector<int> &primos){
    primos.clear();
    if(n < 2) return;

    vector<bool> no_primo(n + 1);
    no_primo[0] = no_primo[1] = true;

    for(long long i = 3; i * i <= n; i += 2){
        if(no_primo[i]) continue;
        for(long long j = i * i; j <= n; j += 2 * i)
            no_primo[j] = true;
    }

    primos.push_back(2);
    for(int i = 3; i <= n; i += 2){
        if(!no_primo[i])
            primos.push_back(i);
    }
}

void criba_sobre_rango(int a, int b, vector<int> &primos){
    a = max(a, 0);
    b = max(b, 0);

    int tam = b - a + 1;

    vector<int> primos_raiz;
    criba(sqrt(b) + 1, primos_raiz);


    vector<char> no_primo(tam);
    primos.clear();
    for(int64_t p : primos_raiz){
        int64_t ini = p * max(p, (a + p - 1) / p);
        for(int64_t m = ini; m <= b; m += p){
            no_primo[m - a] = true;
        }
    }

    for(int i = 0; i < tam; ++i){
        if(no_primo[i] || i + a < 2) continue;
        primos.push_back(i + a);
    }
}

ull gcd_extendido(ull a, ull b, ull &x, ull &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ull x1, y1;
    ull g = gcd_extendido(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

bool encuentra_solucion(ull a, ull b, ull c, ull &x, ull &y, ull &g){
    g = gcd_extendido(LLLabs(a), LLLabs(b), x, y);
    if(c % g) return false;
    x *= c / g;
    y *= c / g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    return true;
}

void cambia_solucion(ull &x, ull &y, ull a, ull b, ull cnt, ull g = 1) {
    x += cnt * b / g;
    y -= cnt * a / g;
}

ull minx_sol_en_intervalo(ull a, ull b, ull c, ull minx, ull miny) {
    ull x, y, g;
    if(!encuentra_solucion(a, b, c, x, y, g)){
        //cerr << "No solucion.\n";
        return 0;
    }

    //cerr << "Ecuacion: " << a << "*k" << " + (" << b << ")d = " << c << '\n';

    //cerr << "Primeras soluciones: k = " << x << ", d = " << y << '\n';

    a /= g;
    b /= g;

    ull sign_a = a > 0 ? +1 : -1;
    ull sign_b = b > 0 ? +1 : -1;

    cambia_solucion(x, y, a, b, (minx - x) / b);
    //cerr << "Minima k: k = " << x << ", d = " << y << '\n';
    if(x < minx) cambia_solucion(x, y, a, b, sign_b);
    //cerr << "Minima k2: k = " << x << ", d = " << y << '\n';
    ull lx1 = x;

    cambia_solucion(x, y, a, b, -(miny - y) / a);
    //cerr << "Minima d: k = " << x << ", d = " << y << '\n';
    if(y < miny) cambia_solucion(x, y, a, b, -sign_a);
    //cerr << "Minima d2: k = " << x << ", d = " << y << '\n';
    ull lx2 = x;

    ull lx = max(lx1, lx2);

    //cerr << lx << '\n';

    return lx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        vector<int> primos, primos_sig;
        criba_sobre_rango(l, r, primos);


        int con = 1;
        while(primos_sig.empty()){
            criba_sobre_rango(r + con, r + con + 1e6, primos_sig);
            con += 1e6;
        }
        primos.push_back(primos_sig[0]);

        ull ans = 0;

        for(int i = 1; i < primos.size(); ++i){
            ull p1 = primos[i - 1], p2 = primos[i];
            ull pot = 1, tmp = p1;
            while(tmp){
                pot *= 10;
                tmp /= 10;
            }

            ull d, S; /// kp2 = S = pot * d + p1 <-> kp2 + (-pot) * d = p1 (S > 0, d > 0)
            //cerr << "Primos: " << p1 << ' ' << p2 << '\n';
            S = p2 * minx_sol_en_intervalo(p2, -pot, p1, 1, 1);
            //cerr << S << '\n';
            ans += S;

        }

        cout << ans << '\n';
    }
}
