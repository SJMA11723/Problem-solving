#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int N;
    cin >> N;
    int64_t x[2*N], y[2*N];
    long double area_total = 0;

    for(int i=0; i<N; i++ ){
        cin >> x[i] >> y[i];
        if(i){
            area_total += x[i - 1] * y[i] - y[i - 1] * x[i];
        }
    }
    area_total += x[N - 1] * y[0] - y[N - 1] * x[0];
    area_total *= 0.5;
    area_total = fabs(area_total);

    for(int i=N; i<2*N; i++ ){
        x[i] = x[i-N];
        y[i] = y[i-N];
    }


    //probar todas las parejas devertices

    long double minimaDif = LLONG_MAX;
    long double A1,A2;
    //cout << area_total << '\n';
    //i es dodne empiza
    for(int i=0; i + 1 < N; i++ ){
        //j es donde termina
        A1 = x[i] * y[i + 1] - y[i] * x[i + 1];
        for(int j=i+2; j < N; j++ ){
            if( i==0 && j ==N-1 ) continue;

            A1 += x[j - 1] * y[j] - y[j - 1] * x[j];
            A1 += x[j] * y[i] - y[j] * x[i];

            //cout << fabs(A1) << ' ' << area_total - fabs(A1*0.5) << '\n';
            minimaDif = min(minimaDif, fabs(area_total - fabs(A1*0.5) - fabs(A1*0.5)));

            A1 -= x[j] * y[i] - y[j] * x[i];
            /*
            //calcuamos el area
            double Area1=0;
            for( int k=i; k< j; k++ ){
                Area1 += x[k]*y[k+1];
                Area1 -= y[k]*x[k+1];
            }
            Area1 += x[j]*y[i];
            Area1 -= y[j]*x[i];
            Area1 /= 2;
            Area1 = abs(Area1);

            double Area2=0;
            for( int k=j; k< i+N; k++ ){
                Area2 += x[k]*y[k+1];
                Area1 -= y[k]*x[k+1];
            }
            Area2 += x[i+N]*y[j];
            Area1 -= y[j]*x[i+N];

            Area2 /=2;
            Area2 = abs(Area2);


            if( abs(Area1-Area2) < minimaDif  ){
                minimaDif =  abs(Area1-Area2);
                A1 = max(Area1, Area2);
                A2 = min(Area1, Area2);
            }*/
        }
    }

    cout << fixed << setprecision(1) <<  minimaDif << '\n';
    //cout << A1 << ' ' << A2 << '\n';

}
