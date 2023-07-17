/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

long long mergeSort(int arr[], int ini, int fin){
    if(ini == fin) return 0;

    int mitad = (ini + fin) / 2;

    long long cnt = 0;

    ///ordenar mitades
    cnt += mergeSort(arr, ini, mitad);
    cnt += mergeSort(arr, mitad + 1, fin);

    ///unir los subarreglos
    int tam1 = mitad - ini + 1, tam2 = fin - mitad;
    int mitad1[tam1], mitad2[tam2];

    ///guardo las mitades
    for(int i = ini, idx = 0; i <= mitad; ++i, idx++)
        mitad1[idx] = arr[i];

    for(int i = mitad + 1, idx = 0; i <= fin; ++i, idx++)
        mitad2[idx] = arr[i];

    for(int i = ini, idx1 = 0, idx2 = 0; i <= fin; ++i){
        if(idx1 < tam1 && idx2 < tam2){ /// si quedan elementos en ambas mitades
            if(mitad1[idx1] < mitad2[idx2]){
                arr[i] = mitad1[idx1++];
            } else {
                arr[i] = mitad2[idx2++];
                cnt += (long long)(tam1 - idx1);
            }
        } else if(idx1 < tam1){ /// si solo hay elementos en mitad1
            arr[i] = mitad1[idx1++];
        } else {
            arr[i] = mitad2[idx2++];
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i) cin >> arr[i];
        cout << mergeSort(arr, 0, n - 1) << '\n';
    }
}

