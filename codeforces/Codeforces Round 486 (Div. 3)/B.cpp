/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool comp(string &a, string &b){
    return b.find(a) != b.npos;
}

void merge_sort(string arr[], int ini, int fin){
    if(ini == fin) return;

    int mitad = (ini + fin) / 2;

    ///ordenar mitades
    merge_sort(arr, ini, mitad);
    merge_sort(arr, mitad + 1, fin);

    ///unir los subarreglos
    int tam1 = mitad - ini + 1, tam2 = fin - mitad;
    string mitad1[tam1], mitad2[tam2];

    ///guardo las mitades
    for(int i = ini, idx = 0; i <= mitad; ++i, idx++)
        mitad1[idx] = arr[i];

    for(int i = mitad + 1, idx = 0; i <= fin; ++i, idx++)
        mitad2[idx] = arr[i];


    for(int i = ini, idx1 = 0, idx2 = 0; i <= fin; ++i){
        if(idx1 < tam1 && idx2 < tam2){ /// si quedan elementos en ambas mitades
            arr[i] = comp(mitad1[idx1], mitad2[idx2]) ? mitad1[idx1++] : mitad2[idx2++];
        } else {
            arr[i] = idx1 < tam1 ? mitad1[idx1++] : mitad2[idx2++];
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string arr[n];
    for(string &s : arr) cin >> s;
    merge_sort(arr, 0, n - 1);
    bool sorted = true;
    for(int i = 1; i < n; ++i) sorted = sorted && comp(arr[i - 1], arr[i]);
    if(sorted){
        cout << "YES\n";
        for(string &s : arr) cout << s << '\n';
    } else cout << "NO\n";
}
