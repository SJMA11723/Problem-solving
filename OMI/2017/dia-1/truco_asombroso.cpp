#include <bits/stdc++.h>

using namespace std;

int n, res;
bool op;
char numero[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> numero;

    for(int i = n - 1; 0 < i; --i){
        if(op){
            if(numero[i] == '1') res += 1;
            else{
                res += 2;
                if(!(numero[i - 1] == '1' && 0 < i - 1)) op = !op;
            }
        } else {
            if(numero[i] == '1'){
                 res += 2;
                 if(numero[i - 1] == '1' && 0 < i - 1) op = !op;
            } else res += 1;
        }
    }

    /**
        Si n = 7, entonces tenemos 111
        Detectamos 1's consecutivos y sumamos, por lo que
        nos queda 1000 (recuerda que la cadena original es de tam 3).
        Entonces vamos eliminando ceros pero en el ciclo solo eliminamos 2:
        1000 -> 10
        111 -> 1
        Ese 0 extra es la operacion extra que sumamos.
    */
    res += op ? 1 : 0;

    cout << res;
}
