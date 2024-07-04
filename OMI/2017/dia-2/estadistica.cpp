/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>
#define MAXVAL 1'000'000

using namespace std;

int izq[MAXVAL + 10];
int der[MAXVAL + 10];
int arr[MAXVAL];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;

    for(int i = 0; i < n; ++i) cin >> arr[i];

    int algo = 0;
    for(int i = 0; i < m; ++i){
        int v; cin >> v;
        algo = v;
        izq[v + 1] = 1;
        der[v] = 1;
    }

    if(*max_element(arr, arr + n) == 0){
        cout << "0\n";
        for(int i = 0; i < n; ++i) cout << algo << ' ';
        cout << '\n';
        return 0;
    }


    izq[0] = -1e9;
    for(int i = 1; i <= MAXVAL + 1; ++i){
        if(izq[i]) izq[i] = i - 1;
        else izq[i] = izq[i - 1];
    }

    der[MAXVAL + 1] = 1e9;
    for(int i = MAXVAL; 0 <= i; --i){
        if(der[i]) der[i] = i;
        else der[i] = der[i + 1];
    }


    for(int i = 0; i < n; ++i){
        if(arr[i]) continue;

        int sig_idx = i;
        while(sig_idx < n && !arr[sig_idx]) sig_idx++;

        int dif1 = 0, dif2 = 0, dif3 = 0, dif4 = 0;

        //cout << mini << ' ' << izq[mini] << ' ' << der[mini] << '\n';

        if(i){
            dif1 += abs(arr[i - 1] - izq[ arr[i - 1] ]);
            dif2 += abs(arr[i - 1] - der[ arr[i - 1] ]);

            if(sig_idx < n){
                dif3 += abs(arr[i - 1] - izq[ arr[sig_idx] ]);
                dif4 += abs(arr[i - 1] - der[ arr[sig_idx] ]);
            }
        }

        if(sig_idx < n){
            if(i){
                dif1 += abs(arr[sig_idx] - izq[ arr[i - 1] ]);
                dif2 += abs(arr[sig_idx] - der[ arr[i - 1] ]);
            }

            dif3 += abs(arr[sig_idx] - izq[ arr[sig_idx] ]);
            dif4 += abs(arr[sig_idx] - der[ arr[sig_idx] ]);
        }

        if(!i) dif1 = dif2 = INT_MAX;
        if(sig_idx >= n) dif3 = dif4 = INT_MAX;

        if(min({dif1, dif2, dif3, dif4}) == dif1) arr[i] = izq[ arr[i - 1] ];
        else if(min({dif1, dif2, dif3, dif4}) == dif2) arr[i] = der[ arr[i - 1] ];
        else if(min({dif1, dif2, dif3, dif4}) == dif3) arr[i] = izq[ arr[sig_idx] ];
        else arr[i] = der[ arr[sig_idx] ];

        for(int j = i + 1; j < sig_idx; ++j) arr[j] = arr[i];
    }

    long long sum = 0;
    for(int i = 1; i < n; ++i) sum += 1ll*abs(arr[i] - arr[i - 1]);
    cout << sum << '\n';
    for(int i = 0; i < n; ++i) cout << arr[i] << ' ';
    cout << '\n';
}
