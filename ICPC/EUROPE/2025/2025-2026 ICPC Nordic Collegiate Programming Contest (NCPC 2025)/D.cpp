#include<bits/stdc++.h>

#define DEBUG if(deb)

bool deb = false;
using namespace std;


template <class T>
struct Point{
    typedef Point P;
    T x,y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y){}
    bool operator< (P p) const {return tie(x,y) < tie(p.x,p.y);}
    bool operator== (P p) const {return tie(x,y) == tie(p.x,p.y);}
    P operator+(P p) const {return P(x+p.x, y+p.y);}
    P operator-(P p) const {return P(x-p.x, y-p.y);}
    T dot(P p) const {return x*p.x+y*p.y;}
    T cross(P p) const { return x*p.y-y*p.x; }
    T cross(P a, P b) const {return (a-*this).cross(b-*this);}
    T dist2() const {return x*x+y*y;}
    double dist() const{return sqrt((double)dist2());}
    friend ostream& operator<<(ostream& os, P p){
        return os<< "("<< p.x<<"," <<p.y<<")";
    }
};



typedef long long ll;
typedef Point<ll> P;

vector<P> convexHull(vector<P> pts){
    if(pts.size() <= 1) return pts;
    sort(pts.begin(), pts.end());
    vector<P> h(pts.size()+1);
    int s = 0, t = 0;
    for(int it = 2; it--; s = --t, reverse(pts.begin(), pts.end()))
        for(P p: pts){
            while(t >= s+2 && h[t-2].cross(h[t-1], p) <= 0) t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin()+t - (t == 2 && h[0] == h[1])};
}

array <P, 2> hullDiameter(vector<P> S){
    int n = S.size(), j = n < 2 ? 0: 1;
    pair<ll, array<P, 2>> res({0,{ S[0], S[0]}});

    for(int i = 0; i < j; i++){
        for(; ; j = (j+1)%n){
            res = max(res, {(S[i]-S[j]).dist2(), {S[i], S[j]}});
            if((S[(j+1)%n]-S[j]).cross(S[i+1]-S[i])>= 0) break;
        }
    }
    return res.second;
}
int main(){
    int n;
    cin>>n;

    vector<P> pts;

    for(int i = 0; i < n; i++){
        ll x,y;
        cin>>x>>y;
        pts.push_back(P(x,y));
    }

    vector<P> chull = convexHull(pts);
   DEBUG  {
    for(auto p : chull){ cout<< p<<" ";}
    cout<<"\n";
   }
    array<P, 2> extremes = hullDiameter(chull);

    auto [a, b] = extremes;

    P start = a;

    sort(pts.begin(), pts.end(),[&start](P u, P v){
        return (u-start).dist2() < (v-start).dist2();
    });
    double ans = 0;
    for(int i = 1; i < n; i++){
        ans+= (pts[i]-pts[i-1]).dist();
    }

    cout<<setprecision(9)<<fixed <<ans<<"\n";

    


}