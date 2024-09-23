#include<bits/stdc++.h>
#define MAXN 1001
using namespace std;

int x[MAXN],y[MAXN];
int vx[MAXN],vy[MAXN];
int n;

double xmin( long double t ){
    long double ans = LONG_MAX;
    for( int i=0; i<n; i++ ) ans = min(  ans, 1.00*x[i]+ t*vx[i]  );
    return ans;
}
double xmax( long double t ){
    long double ans = LONG_MIN;;
    for( int i=0; i<n; i++ ) ans = max(  ans, 1.00*x[i]+ t*vx[i]  );
    return ans;
}
double ymin( long double t ){
    long double ans = LONG_MAX;
    for( int i=0; i<n; i++ ) ans = min(  ans, 1.00*y[i]+ t*vy[i]  );
    return ans;
}
double ymax( long double t ){
    long double ans = LONG_MIN;
    for( int i=0; i<n; i++ ) ans = max(  ans, 1.00*y[i]+ t*vy[i]  );
    return ans;
}

double f( long double t ){
    return xmax(t)-xmin(t);
}

double g( long double t ){
    return ymax(t)-ymin(t);
}
double F( long double t ){
    return max(  g(t), f(t)  );
}
bool cerca( long double a, long double b){
    if( b> a ) swap(a,b);

    return  (a-b) <= 1e-5;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;


    for( int i=0; i<n; i++ ){
        cin >> x[i] >> y[i] >> vx[i] >> vy[i];
    }

    //busqueda ternaria para xmax(t) - xmin(t)
    long double l=0, r=10'000'000;
    int xd= 1000;
//    while( xd--  ){
    for(int i = 0; i < 1000; ++i){
        long double m1 = l + (r-l)/3;
        long double m2 = l + 2*(r-l)/3;

//        cout << l << ' ' << r << "\n";
        if(  F(m1) > F(m2)  ){
            l = m1;
        }else{
            r = m2;
        }

    }
    long double anss = l;


    cout  << fixed << setprecision(3) << F(anss) << '\n';
}
