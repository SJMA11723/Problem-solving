#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

const string special = "!?.,;$#^{}_=+*";

bool is_alpha(char c){
    return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

bool is_num(char c){
    return ('0' <= c && c <= '9');
}

bool is_special(char c){
    return special.find(c) != string::npos;
}

bool valid_character(char c){
    return is_alpha(c) || is_num(c) || is_special(c) || c == ' ';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    cin.ignore();
    bool ok = true;
    while(n--){
        string line;
        getline(cin, line);

        if(line[0] == ' ' || line.back() == ' ')
            ok = false;

        if(!ok) continue;

        int N = sz(line);
        for(int i = 0; i < N; ++i){
            char c = line[i];

            if(!valid_character(c)){
                ok = false;
                //cout << "CARACTER NO VALIDO\n";
                break;
            }

            // caso subindice y superindice
            if(c == '_' || c == '^'){
                if(i + 2 >= N){
                    ok = false;
                    //cout << "LEN INSUFICIENTE\n";
                    break;
                }

                // checa que siga '{'
                if(line[i + 1] != '{'){
                    ok = false;
                    //cout << "NO SIGUE } en indice\n";
                    break;
                }

                // encuentra '}'
                int cierre = -1;
                for(int j = i + 1; j < N; ++j)
                if(line[j] == '}'){
                    cierre = j;
                    break;
                }
                if(cierre == -1){
                    ok = false;
                    //cout << "NO CIERRA }\n";
                    break;
                }

                // lo de adentro es entero
                string num = line.substr(i + 2, cierre - (i + 2));
                for(char digit : num) if(!is_num(digit)){
                    ok = false;
                    //cout << "ADENTRO DE {} NO ES ENTERO VALIDO *NO DIGITO\n";
                    //cout << num << '\n';
                    break;
                }
                if(!ok || sz(num) > 1 && num[0] == '0'){
                    ok = false;
                    //cout << "ADENTRO DE {} NO ES ENTERO VALIDO * CERO IZQ\n";
                    //cout << num << '\n';
                    break;
                }

                // checa que lo anterior sea un entero o 
                if(i == 0 || !(is_num(line[i - 1]) || is_alpha(line[i - 1]))){
                    ok = false;
                    //cout << "LO ANTERIOR A _ + ^ NO ES ENTERO O ALFANUMERICO\n";
                    break;
                }

                i = cierre;
            }

            // caso digitos
            if(is_num(c)){
                int last_digit = i;
                while(last_digit + 1 < N && is_num(line[last_digit + 1]))
                    last_digit++;
                
                // cero a la izquierda
                if(last_digit - i + 1 > 1 && c == '0'){
                    ok = false;
                    //cout << "CERO A LA IZQUIERDA \n";
                    break;
                }

                // rodeado no valido por izquierda
                if(i > 0 && !(is_num(line[i - 1]) || is_alpha(line[i - 1]) || line[i - 1] == ' ')){
                    ok = false;
                    //cout << "NO RODEADO VALIDO\n";
                    //cout << i << '\n';
                    break;
                }

                // rodeado no valido por derecha
                if(last_digit + 1 < N && !(is_num(line[last_digit + 1 ]) || is_alpha(line[last_digit + 1 ]) || line[last_digit + 1] == ' ' || line[last_digit + 1] == '^' || line[last_digit + 1] == '_')){
                    ok = false;
                    //cout << "NO RODEADO VALIDO\n";
                    //cout << i << '\n';
                    break;
                }

                i = last_digit;
            }

            // ceros consecutivos
            if(c == ' ' && line[i - 1] == ' '){
                ok = false;
                //cout << "CEROS CONSECUTIVOS\n";
                break;
            }
        }
    }
    cout << (ok ? "Ok\n" : "Validation failed\n");
}