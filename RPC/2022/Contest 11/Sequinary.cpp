#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin >> str;
    //long double aprox = str.back() - '0';
    unsigned long long a = str.back() - '0', b = 1, pot3 = 3;
    int con = 1;
    for(int i = str.size() - 2; 0 <= i; --i){
        //aprox += (str[i] - '0') * pow(1.5f, con++);

        a *= 2;
        b *= 2;

        //cout << a << ' ' << b << ' ' << pot3 << '\n';

        a += (str[i] - '0') * pot3;

        pot3 *= 3;
    }

    //cout << fixed << setprecision(30) << aprox << '\n';

    unsigned long long gcd = __gcd(a, b);
    a /= gcd;
    b /= gcd;

    if(a < b) cout << a << '/' << b;
    else if(a % b == 0) cout << a / b;
    else cout << a / b << ' ' << a % b << '/' << b;
}
