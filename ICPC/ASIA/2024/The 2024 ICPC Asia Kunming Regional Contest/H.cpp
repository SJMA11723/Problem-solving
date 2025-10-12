#include <bits/stdc++.h>

using namespace std;
const double PI = acos(-1);

typedef long long T;
typedef complex<T> pt;
#define x real()
#define y imag()
#define DEBUG if (debb)

bool debb = false;
T sq(pt p) {
  return p.x * p.x + p.y * p.y;
}
double abs(pt p) {
  return sqrt(sq(p));
}
T dot(pt v, pt w) {
  return (conj(v) * w).x;
}
T cross(pt v, pt w) {
  return (conj(v) * w).y;
}
T orient(pt a, pt b, pt c) {
  return cross(b - a, c - a);
}
double angle(pt v, pt w) {
  double cosTheta = dot(v, w) / abs(v) / abs(w);
  return acos(max(-1.0, min(1.0, cosTheta)));
}
double orientedAngle(pt a, pt b, pt c) {
  if (orient(a, b, c) >= 0) {
    return angle(b - a, c - a);
  } else
    return 2 * PI - angle(b - a, c - a);
}

bool half(pt p) {
  return p.y < 0 || (p.y == 0 && p.x > 0);
}

void polarSort(vector<pt>& v, pt o) {
  sort(v.begin(), v.end(), [&o](pt v, pt w) {
    if (v - o == pt(0, 0))
      return false;
    if (w - o == pt(0, 0))
      return true;

    return make_tuple(half(v - o), 0, sq(v)) <
           make_tuple(half(w - o), cross(v - o, w - o), sq(w));
  });
}

vector<vector<pt>> grouper(vector<pt>& v) {
  vector<vector<pt>> ans;
  pt prev = 0;
  for (auto& p : v) {
    if (ans.empty()) {
      ans.push_back(vector<pt>{p});
      continue;
    }
    long long cr = cross(p, ans.back().back());
    long long dt = dot(p, ans.back().back());
    if (cr == 0 && dt > 0)
      ans.back().push_back(p);
    else
      ans.push_back({p});
  }
  return ans;
}
int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pt> v;
    for (int i = 0; i < n; i++) {
      int px, py;
      cin >> px >> py;
      v.push_back(pt(px, py));
    }
    polarSort(v, pt(0,0));
    vector<vector<pt>> groups = grouper(v);

    
    vector<pair<pt, int>> freqs;

    for (auto& group : groups)
      freqs.push_back({group[0], group.size()});
    for (auto& group : groups)
      freqs.push_back({group[0], group.size()});
    DEBUG{
        for(auto [xx,yy] : freqs){
            cout<<xx<<" "<<yy<<" \n";
        }
    }
    int freqpreff[freqs.size()];

    freqpreff[0] = freqs[0].second;
    for (int i = 1; i < freqs.size(); i++)
      freqpreff[i] = freqpreff[i - 1] + freqs[i].second;
    double ans = 0;
    for (int i = 0; i < groups.size(); i++) {
      int ini = i, fin = i + groups.size() - 1;
      int j = i;
      while (ini <= fin) {
        
        int jmit = (ini + fin) / 2;
        
        int sum = freqpreff[jmit]-freqpreff[i];
        
        DEBUG printf("i = %d, jimit = %d, sum %d\n", i, jmit, sum);
        
        if (sum >= (k)) {
          fin = jmit - 1;
          j = jmit;
        } else {
          ini = jmit + 1;
        }
      }
      DEBUG cout<<freqs[i].first<<" "<<freqs[j].first<<"\n";
      if (freqs[i].first == freqs[j].first) {
        ans = max(ans, 2*PI);
      }
      ans = max(ans, orientedAngle(pt(0, 0), freqs[i].first, freqs[j].first));
    }
    cout<<setprecision(9)<<fixed<<(ans)<<"\n";
  }
  return 0;
}