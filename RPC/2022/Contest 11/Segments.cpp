#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /// para checar los bits validos
    string bitsDigits = "1110111010010010111011101101010111011010111111011010010111111111101111011111111110101010011111110010110110011011";
    set<string> validBits;
    for(int i = 0; i < bitsDigits.size(); i += 7)
        validBits.insert(bitsDigits.substr(i, 7));

    string str;
    int s, n, m, horSeg, vertSeg;
    cin >> s >> str;

    horSeg = s * 3;
    vertSeg = s * 2;

    while(str.size() % 7)
        str = "0" + str;

    /// crea el arreglo de matrices para guardar los digitos
    n = s * 7;
    ///incluyo las columnas de los espacios
    m = s * 5 * str.size() / 7;
    char digits[n][m];
    memset(digits, ' ', n * m);

    for(int d = 0; d < m; d += s * 5){
        int iniBits = d / (s * 5) * 7;

        /// si son bits invalidos entonces lo deja con espacios
        if(!validBits.count(str.substr(iniBits, 7)))
            continue;

        /// revisa cada uno de los segmentos
        /// segmento 6 - horizontal fondo
        if(str[iniBits] == '1'){
            for(int i = 6 * s; i < n; ++i){
                for(int j = 0; j < horSeg; ++j)
                    digits[i][d + j] = 'X';
            }
        }

        /// segmento 5 - vertical izquierda abajo
        if(str[iniBits + 1] == '1'){
            for(int i = 4 * s; i < 6 * s; ++i)
                for(int j = 0; j < s; ++j)
                    digits[i][d + 2 * s + j] = 'X';
        }

        /// segmento 4 - vertical derecha abajo
        if(str[iniBits + 2] == '1'){
            for(int i = 4 * s; i < 6 * s; ++i)
                for(int j = 0; j < s; ++j)
                    digits[i][d + j] = 'X';
        }

        /// segmento 3 - horizontal medio
        if(str[iniBits + 3] == '1'){
            for(int i = 3 * s; i < 4 * s; ++i){
                for(int j = 0; j < horSeg; ++j)
                    digits[i][d + j] = 'X';
            }
        }

        /// segmento 2 - vertical derecha arriba
        if(str[iniBits + 4] == '1'){
            for(int i = s; i < 3 * s; ++i)
                for(int j = 0; j < s; ++j)
                    digits[i][d + 2 * s + j] = 'X';
        }

        /// segmento 1 - vertical izquierda arriba
        if(str[iniBits + 5] == '1'){
            for(int i = s; i < 3 * s; ++i)
                for(int j = 0; j < s; ++j)
                    digits[i][d + j] = 'X';
        }

        /// segmento 0 - horizontal inicial
        if(str[iniBits + 6] == '1'){
            for(int i = 0; i < s; ++i){
                for(int j = 0; j < horSeg; ++j)
                    digits[i][d + j] = 'X';
            }
        }

        /// para identificar espacios entre digitos los asigno a cero
        /// servira mas adelante para no imprimir espacios extra al final de las lineas
        for(int i = 0; i < n; ++i){
            for(int j = d + horSeg; j < (d + horSeg + 2 * s); ++j)
                digits[i][j] = 0;
        }
    }

    int lim = 80 / (s * 5) * s * 5;
    for(int ini = 0; ini < m; ini += lim){
        /**
            imprime el maximo de digitos entre cada 80 columnas
            incluyendo los espacios entre digitos
        */
        for(int i = 0; i < n; ++i){
            for(int j = ini; j < m && j < ini + lim; ++j){
                /// si ya no hay espacio, entonces paso a la siguiente linea
                if(!digits[i][j] && ini + lim - j <= s * 2){
                    break;
                }

                if(!digits[i][j]) cout << ' ';
                else cout << digits[i][j];
            }
            cout << '\n';
        }

        /// imprime s lineas en blanco entre cada linea de digitos
        for(int i = 0; i < s; ++i)
            cout << "\n";
    }
}
