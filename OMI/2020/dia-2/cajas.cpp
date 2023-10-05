/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

/// ARREGLADO: faltaba un -1 en maxi = min(...).
void solve27(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = 11;
    do{
        int maxi = 0;
        int pilas = 0;
        for(int i = 0; i < n; ++i){
            if(maxi == 0){
                pilas++;
                maxi = arr[i];
            } else {
                maxi = min(maxi - 1, arr[i]);
            }
        }
        ans = min(ans, pilas);
    }while(next_permutation(arr, arr + n)); /// O(n) para pasar a la siguiente permutacion
    /// Complejidad total: O(n^2*n!)
    cout << ans << '\n';
}

void solve61(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] == -1) continue;
        ans++;
        int tam = 1;
        for(int j = i + 1; j < n; ++j){
            if(arr[j] == -1) continue;
            if(tam <= arr[j]){
                arr[j] = -1;
                tam++;
            }
        }
    }
    cout << ans << '\n';
}

void solve100A(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(arr, arr + n);

    map<int, int> cub;

    for(int i = 0; i < n; ++i){
        /// {clave, valor}
        auto it = cub.begin();
        if(cub.size() == 0 || it->first > arr[i]){
            cub[1]++;
        } else {
            it->second--;
            cub[it->first + 1]++;

            if(it->second == 0){
                cub.erase(it);
            }
        }
    }

    int ans = 0;
    for(auto it : cub){
        ans += it.second;
    }
    cout << ans << '\n';
}

/// Funcion auxiliar para solve100B().
bool es_valido(int p, int n, int arr[]){
    bool se_puede = true;
    for(int i = 0; i < p && se_puede; ++i){
        int tam = 0;
        for(int j = i; j < n; j += p){
            if(tam > arr[j]){
                se_puede = false;
                break;
            }
            tam++;
        }
    }

    return se_puede;
}

void solve100B(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int ini = 1, fin = n;
    while(ini < fin){
        int mitad = (ini + fin) / 2;
        if(es_valido(mitad, n, arr)) fin = mitad;
        else ini = mitad + 1;
    }
    cout << ini << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve27();
}
