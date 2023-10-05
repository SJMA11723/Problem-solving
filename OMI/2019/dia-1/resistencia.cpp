/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

/// BigNumber improvisado con cosas para debuggear
struct big_number {
    string num;

    big_number(){
        num = "0";
    }

    big_number(string n){
        num = n;
        if(num == "") num = "0";
    }

    big_number(char n[]){
        num = n;
        if(num == "") num = "0";
    }

    big_number(long long n){
        num = to_string(n);
    }

    big_number(int n, int arr[], bool is_bucket){
        num = "";
        for(int i = 0; i < n; ++i){
            if(is_bucket){
                for(int j = 0; j < arr[i]; ++j)
                    num += to_string(i);
            } else {
                num += to_string(arr[i]);
            }
        }
    }

    int size(){
        return num.size();
    }

    big_number mult_digits(){
        big_number res = 1;
        for(int i = 0; i < num.size(); ++i){
            res *= (num[i] - '0');
        }
        return res;
    }

    string operator=(string n){
        return n;
    }

    string operator=(char n[]){
        return n;
    }

    string operator=(long long n){
        return to_string(n);
    }

    friend ostream &operator<<(ostream &out, const big_number &n){
        out << n.num;
        return out;
    }

    /// multiplicacion por 1 digito
    big_number operator*(int n){
        string res = num;
        int llevo = 0;
        for(int i = res.size() - 1; 0 <= i; --i){
            int d = res[i] - '0';
            d = d * n + llevo;
            res[i] = d % 10 + '0';
            llevo = d / 10;
        }
        if(llevo) res = to_string(llevo) + res;
        return res;
    }

    big_number & operator*=(int n){
        big_number tmp(num);
        tmp = tmp * n;
        num = tmp.num;
        return *this;
    }

    bool operator==(big_number b){
        return num == b.num;
    }

    bool operator<(big_number b){
        if(num.size() == b.size()) return num < b.num;
        return num.size() < b.size();
    }
};

int digitos[10];
big_number ans;
int max_r = 0;

int resistencia(big_number n){
    int res = 0;
    big_number tmp = n;

    while(tmp.size() > 1){
        tmp = tmp.mult_digits();
        res++;
    }

    return res;
}

/// #digitos, digito actual
void generar(int k, int d){
    big_number n(10, digitos, true);

    int r = resistencia(n);
    if(max_r < r){
        max_r = r;
        ans = n;
        cout << max_r << ' ' << ans << '\n';
    } else if(max_r == r){
        if(ans == "0" || n < ans){
            ans = n;
            cout << max_r << ' ' << ans << '\n';
        }
    }

    if(n.size() >= k || d >= 10) return;

    if(d == 2){
        /// Lo elijo
        digitos[d] = 1;
        generar(k, d + 1);

        /// No lo elijo
        digitos[d] = 0;
        generar(k, d + 1);
        return;
    }

    if(d == 3){
        /// No lo elijo
        digitos[d] = 0;
        generar(k, d + 1);

        /// Lo elijo si no hay 2's
        if(!digitos[2]){
            digitos[d] = 1;
            generar(k, d + 1);
            digitos[d] = 0;
        }
        return;
    }

    if(d == 4){
        digitos[d] = 0;
        generar(k, d + 1);
        if(!digitos[2] && !digitos[3]){
            digitos[d] = 1;
            generar(k, d + 1);
            digitos[d] = 0;
        }
        return;
    }

    if(d == 5 && (digitos[2] || digitos[4])){
        digitos[d] = 0;
        generar(k, d + 1);
        return;
    }

    if((d == 6 || d == 8) && digitos[5]){
        digitos[d] = 0;
        generar(k, d + 1);
        return;
    }

    if(d == 6){
        digitos[d] = 0;
        generar(k, d + 1);
        if(!digitos[3] && !digitos[4]){
            digitos[d] = 1;
            generar(k, d + 1);
            digitos[d] = 0;
        }
        return;
    }

    for(int i = 0; i + n.size() <= k; ++i){
        digitos[d] = i;
        generar(k, d + 1);
    }
    digitos[d] = 0;
}

int main(){
    for(int i = 0; i <= 1000; ++i){
        cout << "Generando para " << i << " digitos.\n";
        generar(i, 2);
    }
    cout << max_r << ' ' << ans << '\n';
}
