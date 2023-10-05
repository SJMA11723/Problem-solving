#include <bits/stdc++.h>

using namespace std;

const long double PI = 3.141592653589793238L;

long double f(long double x, long double y, long double z){
    return -y * z/x  + y;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long double y,x,r;
    cin>>y>>x>>r;
    if(x<=r&&x>=-r){
    	cout<< "0\n";
    	return 0;
	}

    long double a = ( 4*y*y*y*y - 4*(y*y + x*x) * (y*y - r*r) );

    if(a<0){
        cout << "-1\n";
        return 0;
    }

    long double x_1 = ( 2*y*y*x + x*sqrt(a)) / (2*(y*y+x*x));
    long double x_2 = ( 2*y*y*x - x*sqrt(a)) / (2*(y*y+x*x));

    vector<long double> puntos;
    if(f(x, y, x_1) >= 0 && f(x,y,x_1)<=y) puntos.push_back(x_1);
    if(f(x, y, x_2) >= 0 && f(x,y,x_2)<=y) puntos.push_back(x_2);

    if(puntos.empty()){
        cout << "-1\n";
        return 0;
    }

    long double ans_1 = acos(puntos[0] / r) * 180.0 / PI;
    if(ans_1 > 90) ans_1 = 180 - ans_1;

    long double ans_2 = 10'000'000'000'000;
    if(puntos.size() == 2){
        ans_2 = acos(puntos[1] / r) * 180.0 / PI;
        if(ans_2 > 90) ans_2 = 180 - ans_2;
    }

    cout << fixed << setprecision(16) << min(ans_1, ans_2) << '\n';
    return 0;
}
