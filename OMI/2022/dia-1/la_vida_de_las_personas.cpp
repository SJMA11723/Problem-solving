/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

/**
    tipo 1: nacimiento, b
    tipo 2: pregunta, idx = b
    tipo 3: fallecimiento, a
*/
struct evento{
    int tipo;
    int fecha, b;

    bool operator<(evento &e){
        if(fecha == e.fecha) return tipo < e.tipo;
        return fecha < e.fecha;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<evento> eventos;

    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        eventos.push_back({1, a, b});
        eventos.push_back({3, b, a});
    }

    for(int i = 0; i < q; ++i){
        int x; cin >> x;
        eventos.push_back({2, x, i});
    }

    sort(eventos.begin(), eventos.end());

    int cnt_vivas = 0;
    int vivas[q] = {};
    int joven[q] = {};
    int anciano[q] = {};
    deque< pair<int, int> > personas;

    for(evento &e : eventos){
        if(e.tipo == 1){
            cnt_vivas++;
            personas.push_back({e.fecha, e.b});
        } else if(e.tipo == 2){
            while(personas.size() && personas.back().second < e.fecha) personas.pop_back();
            while(personas.size() && personas.front().second < e.fecha) personas.pop_front();

            if(personas.size()){
                vivas[e.b] = cnt_vivas;
                joven[e.b] = e.fecha - personas.back().first;
                anciano[e.b] = e.fecha - personas.front().first;
            }
        } else cnt_vivas--;
    }

    for(int i = 0; i < q; ++i)
        cout << vivas[i] << ' ' << joven[i] << ' ' << anciano[i] << '\n';
}
