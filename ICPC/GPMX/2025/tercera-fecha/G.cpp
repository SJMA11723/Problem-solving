#include <bits/stdc++.h>
#define DEBUG if(deb)

bool deb = false;
using namespace std;

long long h1, h2,b;


long double binexp(double base, int exp){

    if(exp == 1) return base;
    if(exp%2 == 0){
        long double v = binexp(base, exp/2);
        return v*v; 
    }
    else return base*binexp(base, exp-1);
}
long double f(int n){
    long double val = 1 - 1.0L/b;
    return binexp(val, n);
}

int main(){
    if(!deb)ios_base::sync_with_stdio(0);
    if(!deb)cin.tie(0);
    if(!deb)cout.tie(0); 
    
    int t; cin >> t;

    while( t-- ){
        
        cin>>h1>>h2>>b;

        int ans = 0;
        int l = 1,r;
        long double thang = (1.0L*h2)/h1;
        for(r = 1; ; r*=2){
            if(f(r) <= thang) break;
        }
        

        while(l <= r){
            
            int m = (l+r)/2;
            DEBUG cout<<l<<" "<<r<<" "<<m<<"\n";
            long double ff = f(m);

            DEBUG cout<<ff<<" "<<thang<<"\n";
            if(ff <= thang){
                ans = m;
                r = m-1;
            }
            else{
                l = m+1;
            }
        }

        cout<<ans<<"\n";
    }
    

}