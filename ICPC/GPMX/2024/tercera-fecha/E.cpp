#include <bits/stdc++.h>
#define MUCHO 100

using namespace std;

int n;
int joyas[MUCHO][MUCHO];

bool valido(){
    int ant = -1;
    for(int c=0; c < n; c++){
        for(int k=0; k <  n; k++){
            if(joyas[c][k] > ant){
                ant = joyas[c][k];
            }
            else{
                return false;
            }
        }
        ant = -1;
    }
    ant = -1;
    for(int c=0; c < n; c++){
        for(int k=0; k<  n; k++){
            if(joyas[k][c] > ant){
                ant = joyas[k][c];
            }
            else{
                return false;
            }
        }
        ant = -1;
    }
    return true;
}

void rota(){
    int aux[MUCHO][MUCHO];
    for(int c=0; c < n; c++){
        for(int k=0; k < n; k++){
            aux[c][k] = joyas[c][k];
        }
    }
    for(int c=0; c < n; c++){
        for(int k=0; k < n; k++){
            joyas[n-k-1][c] = aux[c][k];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int c=0; c < n; c++){
        for(int k=0; k < n; k++){
            cin >> joyas[c][k];
        }
    }
    if(valido()){
        cout << 0 << endl;
        return 0;
    }
    rota();
    if(valido()){
        cout << 1 << endl;
        return 0;
    }
    rota();
    if(valido()){
        cout << 2 << endl;
        return 0;
    }
    rota();
    if(valido()){
        cout << 3 << endl;
    }
    return 0;
}
