/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <iostream>
#define MAXN 100

using namespace std;

long long C[MAXN + 1];

int main(){
    C[0] = 1;
    for(int i = 1; i <= MAXN; ++i)
    for(int j = 0; j < i; ++j) C[i] += C[j] * C[i - 1 - j];

    int n; cin >> n;
    while(n != -1){
        cout << C[n] << '\n';
        cin >> n;
    }
}
