#include<bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, g; cin >> n >> g;
    int arr[n], total = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        total += arr[i];
    }

    int lim = 1 << n;
    int M = n + 1, C = 0;
    for(int mask = 0; mask < lim; ++mask){
        int sum = 0;
        for(int i = 0; i < n; ++i)
            if(is_on(mask, i)) sum += arr[i];

        if(sum * 100 / total >= g){
            int tam = __builtin_popcount(mask);
            if(M == tam) C++;
            else if(tam < M){
                M = tam;
                C = 1;
            }
        }
    }

    cout << M << ' ' << C << '\n';
    for(int mask = 0; mask < lim; ++mask){
        int sum = 0;
        for(int i = 0; i < n; ++i)
            if(is_on(mask, i)) sum += arr[i];

        int tam = __builtin_popcount(mask);
        if(sum * 100 / total >= g && tam == M){
            cout << sum * 100 / total << ' ';
            int idx = 0;
            for(int i = 0; i < n; ++i)
                if(is_on(mask, i)) cout << i + 1 << " \n"[tam == ++idx];
        }
    }

    return 0;
}
