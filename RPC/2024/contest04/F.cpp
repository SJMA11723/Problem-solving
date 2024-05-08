#include <bits/stdc++.h>

using namespace std;

long double ans = LLONG_MAX;

void busqueda(int n, vector<pair<int, int>> &puntos, long double mini, long double maxi){
    if(n == 0){
        ans = min(ans, maxi - mini);
        //cout << " | " << mini << ' ' << maxi << '\n';
        return;
    }

    if(maxi - mini >= ans){
         //cout << " | " << mini << ' ' << maxi << '\n';
         return;
    }

    n *= 3;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
           for(int k = j + 1; k < n; ++k){
                long double area = puntos[i].first * puntos[j].second - puntos[i].second * puntos[j].first +
                                   puntos[j].first * puntos[k].second - puntos[j].second * puntos[k].first +
                                   puntos[k].first * puntos[i].second - puntos[k].second * puntos[i].first;
                area = fabs(area) * 0.5;

                pair<int, int> a, b, c;
                a = puntos[i];
                b = puntos[j];
                c = puntos[k];

                puntos.erase(puntos.begin() + k);
                puntos.erase(puntos.begin() + j);
                puntos.erase(puntos.begin() + i);

                //cout << area << ' ';
                busqueda(n / 3 - 1, puntos, min(mini, area), max(maxi, area));

                puntos.insert(puntos.begin() + i, a);
                puntos.insert(puntos.begin() + j, b);
                puntos.insert(puntos.begin() + k, c);
           }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> puntos;
    for(int i = 0; i < 3 * n; ++i){
        int x, y;
        cin >> x >> y;
        puntos.push_back({x, y});
    }

    busqueda(n, puntos, INT_MAX, 0);

    cout << fixed << setprecision(1) << ans << '\n';
}
