/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

struct pt {
    long long x, y;
    pt(){}
    pt(long long a, long long b): x(a), y(b){}

    bool operator==(const pt &b){
        return x == b.x && y == b.y;
    }
};

pt minAb(pt a, pt b){
    if(a.y == b.y){
        if(b.x < a.x) return a:
        return b;
    }
    if(a.y < b.y) return a;
    return b;
}

pt maxAr(pt a, pt b){
    if(b.y == a.y){
        if(a.x < b.x) return a;
        return b;
    }
    if(b.y < a.y) return a;
    return b;
}

pt minIzq(pt a, pt b){
    if(a.x == b.x){
        if(a.y < b.y) return a;
        return b;
    }
    if(a.x < b.x) return a;
    return b;
}

pt maxDer(pt a, pt b){
    if(a.x == b.x){
        if(b.y < a.y) return a;
        return b;
    }
    if(b.x < a.x) return a;
    return b;
}

int orientation(pt a, pt b, pt c) {
    long long v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    a = st;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, np; cin >> n;
    vector<pt> puntos;
    np = n;
    while(np--){
        int x, y; cin >> x >> y;
        puntos.push_back(pt(x, y));
    }

    convex_hull(puntos, true);

    np = puntos.size();

    long long ans = 0;

    pt arriba, abajo, izquierda, derecha;

    arriba = abajo = izquierda = derecha = puntos[0];

    for(int i = 0; i < np; ++i){
        arriba = maxAr(arriba, puntos[i]);
        abajo = minAb(abajo, puntos[i]);
        izquierda = minIzq(izquierda, puntos[i]);
        derecha = maxDer(derecha, puntos[i]);
    }

    cout << ans << '\n';
}
